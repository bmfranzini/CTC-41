/****************************************************/
/* File: tiny.y                                     */
/* The TINY Yacc/Bison specification file           */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/
%{
#define YYPARSER /* distinguishes Yacc output from other code files */

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"

#define YYSTYPE TreeNode *
static char * savedName; /* for use in assignments */
static int savedLineNo;  /* ditto */
static TreeNode * savedTree; /* stores syntax tree for later return */
static int yylex(void);
int yyerror(char *);

%}

%token INT VOID
%token ID NUM
%token EQUALS PLUS MINUS TIMES DIVIDE
%token LEQ LT GT GEQ EQ NEQ
%token IF ELSE WHILE RETURN
%token LPAREN RPAREN LBRACKET RBRACKET LBRACE RBRACE SEMI COMMA

%% /* Grammar for TINY */

programa:
    declaração_lista { savedTree = $1; }
;

declaração_lista:
    declaração_lista declaração 
    { 
        YYSTYPE t = $1;
        if (t) {
            while (t->sibling) t = t->sibling;
            t->sibling = $2;
            $$ = $1;
        } else {
            $$ = $2;
        }
    }
    | declaração { $$ = $1; }
;

declaração:
    var_declaração { $$ = $1; }
    | fun_declaração { $$ = $1; }
;

var_declaração:
    tipo_especificador ID SEMI
        { $$ = newDecNode(VarDecK);
          $$->attr.name = copyString($2);
          $$->type = $1;
        }
    | tipo_especificador ID LBRACKET NUM RBRACKET SEMI
        { $$ = newDecNode(ArrDecK);
          $$->attr.arr.name = copyString($2);
          $$->attr.arr.size = $4;
          $$->type = $1;
        }
;

tipo_especificador:
    INT { $$ = Integer; } // Usando os tipos de enum definidos
    | VOID { $$ = Void; }
;

fun_declaração:
    tipo_especificador ID LPAREN params RPAREN composto_decl
    { 
        $$ = newDecNode(FunDecK);
        $$->attr.fun.name = copyString($2);
        $$->type = $1;
        $$->child[0] = $4;
        $$->child[1] = $6;
    }
;

params:
    param_lista { $$ = $1; }
    | VOID { $$ = NULL; }
;

param_lista:
    param_lista COMMA param
    { 
        YYSTYPE t = $1;
        while (t->sibling) t = t->sibling;
        t->sibling = $3;
        $$ = $1;
    }
    | param { $$ = $1; }
;

param:
    tipo_especificador ID
    {
        $$ = newDecNode(VarDecK); // Adaptação para o nó de declaração
        $$->attr.name = copyString($2);
        $$->type = $1;
    }
    | tipo_especificador ID LBRACKET RBRACKET
    {
        $$ = newDecNode(ArrDecK); // Adaptação para o nó de declaração de array
        $$->attr.arr.name = copyString($2);
        $$->type = $1;
    }
;

%%

int yyerror(char * message)
{ pce("Syntax error at line %d: %s\n",lineno,message);
  pce("Current token: ");
  printToken(yychar,tokenString);
  Error = TRUE;
  return 0;
}

/* yylex calls getToken to make Yacc/Bison output
 * compatible with ealier versions of the TINY scanner
 */
static int yylex(void)
{ return getToken(); }

TreeNode * parse(void)
{ yyparse();
  return savedTree;
}

