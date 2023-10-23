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


#define YYSTYPE TreeNode*
static char * savedNameVarDeclaracao;
static char * savedNameVarDeclaracao2;
static char * savedNameFunDeclaracao;
static char * savedNameParam;
static char * savedNameVar;
static char * savedNameVar2;
static char * savedNameFator;
static char * savedNameAtivacao; /* for use in assignments */
static int savedLineNo;
static int savedLineNo2;  /* ditto */
static TreeNode * savedTree; /* stores syntax tree for later return */
static int yylex(void);
Stack stack;
int yyerror(char *);
%}

%token 
    IF ELSE INT RETURN VOID WHILE 
    PLUS MINUS TIMES OVER LT LET BT BET EQUAL DIF 
    ASSIGN SEMI COMMA LPAREN RPAREN LBRACKET RBRACKET LBRACE RBRACE
    NUM ID ERROR

%% /* Grammar for TINY */

programa:
    declaracao_lista { savedTree = $1; }
;

declaracao_lista:
    declaracao_lista declaracao 
    { 
        YYSTYPE t = $1;
        if (t != NULL) {
            while (t->sibling != NULL) t = t->sibling;
            t->sibling = $2;
            $$ = $1;
        } else {
            $$ = $2;
        }
    }
    | declaracao { $$ = $1; }
;

declaracao:
    var_declaracao { $$ = $1; }
    | fun_declaracao { $$ = $1; }
;

var_declaracao:
    tipo_especificador ID { savedNameVarDeclaracao = copyString(lastTokenString);
                   savedLineNo = lineno; } SEMI
    { 
        $$ = $1;
        YYSTYPE newNodeS2 = newExpNode(IdK);
        newNodeS2->attr.name = savedNameVarDeclaracao;
        newNodeS2->lineno = savedLineNo;
        $1->child[0] = newNodeS2;
    }
    | tipo_especificador ID { savedNameVarDeclaracao = copyString(lastTokenString);
                   savedLineNo = lineno; } LBRACKET NUM { savedNameVarDeclaracao2 = copyString(tokenString);
                   savedLineNo2 = lineno; } RBRACKET SEMI
    { 
        $$ = $1;
        YYSTYPE newNodeS2 = newExpNode(IdK);
        newNodeS2->attr.name = savedNameVarDeclaracao;
        newNodeS2->lineno = savedLineNo;
        $1->child[0] = newNodeS2;

        YYSTYPE newNodeS3 = newExpNode(ConstK);
        newNodeS3->attr.val = atoi(savedNameVarDeclaracao2);
        newNodeS3->lineno = savedLineNo2;
        newNodeS2->child[0] = newNodeS3;

    }
;


tipo_especificador:
    INT 
    { 
        $$ = newDecNode(DeclarationK); 
        $$->type = Integer;
        $$->attr.name = copyString("int");
    }
    | VOID 
    { 
        $$ = newDecNode(DeclarationK); 
        $$->type = Void;
        $$->attr.name = copyString("void");
    }
;

fun_declaracao:
    tipo_especificador ID { savedNameFunDeclaracao = copyString(lastTokenString);
                  savedLineNo = lineno; } LPAREN params RPAREN composto_decl
    { 
        $$ = $1;
        YYSTYPE newNodeS2 = newExpNode(IdK);
        newNodeS2->attr.name = savedNameFunDeclaracao;
        newNodeS2->lineno = savedLineNo;
        $1->child[0] = newNodeS2;
        $1->child[0]->child[0] = $5;
        $1->child[0]->child[1] = $7;

        //$$->type = $1->type;
        //$$->child[0] = $4;
        //$$->child[1] = $6;
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
    tipo_especificador ID { savedNameParam = copyString(lastTokenString);
                   savedLineNo = lineno; }
    {
        $$ = $1;
        YYSTYPE newNodeS2 = newExpNode(IdK);
        newNodeS2->attr.name = savedNameParam;
        newNodeS2->lineno = savedLineNo;
        $1->child[0] = newNodeS2;
    }
    | tipo_especificador ID { savedNameParam = copyString(lastTokenString);
                   savedLineNo = lineno; } LBRACKET RBRACKET
    {
        $$ = $1;
        YYSTYPE newNodeS2 = newExpNode(IdK);
        newNodeS2->attr.name = savedNameParam;
        newNodeS2->lineno = savedLineNo;
        $1->child[0] = newNodeS2;
    }
;

composto_decl:
    LBRACE local_declaracoes statement_lista RBRACE
        {
            if($2 != NULL){
                $$ = $2;
                YYSTYPE t = $$;
                while (t->sibling) t = t->sibling;
                t->sibling = $3;
            }
            else {
                $$ = $3;
            }
        }
    ;

local_declaracoes:
    local_declaracoes var_declaracao
        {
            YYSTYPE t = $1;
            if (t != NULL) {
                while (t->sibling) t = t->sibling;
                t->sibling = $2;
                $$ = $1;
            } else {
                $$ = $2;
            }
        }
    | /* vazio */
        {
            $$ = NULL;
            //$$ = $2;
        }
    ;

statement_lista:
    statement_lista statement
        {
            YYSTYPE t = $1;
            if (t != NULL) {
                while (t->sibling) t = t->sibling;
                t->sibling = $2;
                $$ = $1;
            } else {
                $$ = $2;
            }
        }
    | /* vazio */
        {
            $$ = NULL;
        }
    ;

statement:
    expressao_decl {
            $$ = $1;
        }
    | composto_decl {
            $$ = $1;
        }
    | selecao_decl {
            $$ = $1;
        }
    | iteracao_decl {
            $$ = $1;
        }
    | retorno_decl {
            $$ = $1;
        }
    ;

expressao_decl:
    expressao SEMI
        {
            $$ = $1;
        }
    | SEMI
        {
            $$ = NULL;
        }
    ;

selecao_decl:
    IF LPAREN expressao RPAREN statement
        {
            $$ = newStmtNode(IfK);
            $$->child[0] = $3;
            $$->child[1] = $5;
        }
    | IF LPAREN expressao RPAREN statement ELSE statement
        {
            $$ = newStmtNode(IfK);
            $$->child[0] = $3;
            $$->child[1] = $5;
            $$->child[2] = $7;
        }
    ;

iteracao_decl:
    WHILE LPAREN expressao RPAREN statement
        {
            $$ = newStmtNode(WhileK);
            $$->child[0] = $3;
            $$->child[1] = $5;
        }
    ;

retorno_decl:
    RETURN SEMI
        {
            $$ = newStmtNode(ReturnK);
        }
    | RETURN expressao SEMI
        {
            $$ = newStmtNode(ReturnK);
            $$->child[0] = $2;
        }
    ;

expressao:
    var ASSIGN expressao
        {
            $$ = newStmtNode(AssignK);
            $$->child[0] = $1;
            $$->child[1] = $3;
        }
    | simples_expressao {
        $$ = $1;
    }
    ;

var:
    ID { savedNameVar = copyString(lastTokenString);
                   savedLineNo = lineno; }
        {
            $$ = newExpNode(IdK);
            $$->attr.name = savedNameVar;
            $$->lineno = savedLineNo;
        }
    | ID { savedNameVar2 = copyString(lastTokenString);
                   savedLineNo = lineno; } LBRACKET expressao RBRACKET
        {
            $$ = newExpNode(IdK);
            $$->attr.name = savedNameVar2;
            $$->lineno = savedLineNo;
            $$->child[0] = $4;
        }
    ;

simples_expressao:
    soma_expressao relacional soma_expressao
        {
            //$$ = newExpNode(OpK);
            //$$->attr.op = $2->attr.op;
            $$ = $2;
            $$->child[0] = $1;
            $$->child[1] = $3;
        }
    | soma_expressao {
        $$ = $1;
    }
    ;

relacional:
    LET { 
        $$ = newExpNode(OpK);
        $$->attr.op = LET;
        $$->attr.name = copyString("<=");
        }
    | LT { 
        $$ = newExpNode(OpK);
        $$->attr.op = LT;
        $$->attr.name = copyString("<");
        }
    | BT { 
        $$ = newExpNode(OpK);
        $$->attr.op = BT;
        $$->attr.name = copyString(">");
        }
    | BET { 
        $$ = newExpNode(OpK);
        $$->attr.op = BET;
        $$->attr.name = copyString(">=");
        }
    | EQUAL { 
        $$ = newExpNode(OpK);
        $$->attr.op = EQUAL;
        $$->attr.name = copyString("==");
        }
    | DIF { 
        $$ = newExpNode(OpK);
        $$->attr.op = DIF;
        $$->attr.name = copyString("!=");
        }
    ;

soma_expressao:
    soma_expressao soma termo
        {
            $$ = $2;
            $$->child[0] = $1;
            $$->child[1] = $3;
        }
    | termo {
        $$ = $1;
    }
    ;

soma:
    PLUS { 
        $$ = newExpNode(OpK);
        $$->attr.op = PLUS;
        $$->attr.name = copyString("+");
        }
    | MINUS { 
        $$ = newExpNode(OpK);
        $$->attr.op = MINUS;
        $$->attr.name = copyString("-"); 
        }
    ;

termo:
    termo mult fator
        {
            //$$ = newExpNode(OpK);
            //$$->attr.op = $2->attr.op;
            $$ = $2;
            $$->child[0] = $1;
            $$->child[1] = $3;
        }
    | fator {
        $$ = $1;
    }
    ;

mult:
    TIMES { 
        $$ = newExpNode(OpK);
        $$->attr.op = TIMES;
        $$->attr.name = copyString("*");
        }
    | OVER { 
        $$ = newExpNode(OpK);
        $$->attr.op = OVER; 
        $$->attr.name = copyString("/");
        }
    ;

fator:
    LPAREN expressao RPAREN { 
        $$ = $2;     
    }
    | var {
        $$ = $1;
    }
    | ativacao {
        $$ = $1;
    }
    | NUM { savedNameFator = copyString(tokenString);
                   savedLineNo = lineno; }
        {
            $$ = newExpNode(ConstK);
            $$->attr.val = atoi(savedNameFator);
            $$->lineno = savedLineNo;
        }
    ;

ativacao:
    ID { push(copyString(lastTokenString));
                   savedLineNo = lineno; } LPAREN args RPAREN
        {
            //$$ = newExpNode(IdK);
            $$ = newExpNode(FunK);
            $$->attr.name = pop();
            $$->lineno = savedLineNo;
            $$->child[0] = $4;
        }
    ;

args:
    arg_lista {
        $$ = $1;
    }
    | /* vazio */
        {
            $$ = NULL;
        }
    ;

arg_lista:
    arg_lista COMMA expressao
        {
            YYSTYPE t = $1;
            if (t != NULL) {
                while (t->sibling) t = t->sibling;
                t->sibling = $3;
                $$ = $1;
            } else {
                $$ = $3;
            }
        }
    | expressao {
        $$ = $1;
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
{ 
    strncpy(lastTokenString, tokenString, MAXTOKENLEN);
    return getToken(); }

TreeNode * parse(void)
{ 
    yyparse();
  return savedTree;
}

