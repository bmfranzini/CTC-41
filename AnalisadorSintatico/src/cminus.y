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
static char * savedName;
static char * savedName2; /* for use in assignments */
static int savedLineNo;
static int savedLineNo2;  /* ditto */
static TreeNode * savedTree; /* stores syntax tree for later return */
static int yylex(void);
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
    tipo_especificador ID { savedName = copyString(lastTokenString);
                   savedLineNo = lineno; } SEMI
    { 
        $$ = $1;
        YYSTYPE newNodeS2 = newExpNode(IdK);
        fprintf(stdout, "savedName = %s\n", savedName);
        newNodeS2->attr.name = savedName;
        newNodeS2->lineno = savedLineNo;
        $1->child[0] = newNodeS2;
    }
    | tipo_especificador ID { savedName = copyString(lastTokenString);
                   savedLineNo = lineno; } LBRACKET NUM { savedName2 = copyString(tokenString);
                   savedLineNo2 = lineno; } RBRACKET SEMI
    { 
        $$ = $1;
        YYSTYPE newNodeS2 = newExpNode(IdK);
        fprintf(stdout, "savedName = %s\n", savedName);
        newNodeS2->attr.name = savedName;
        newNodeS2->lineno = savedLineNo;
        $1->child[0] = newNodeS2;
        fprintf(stdout, "savedName2 = %s\n", savedName2);

        YYSTYPE newNodeS3 = newExpNode(ConstK);
        newNodeS3->attr.val = atoi(savedName2);
        newNodeS3->lineno = savedLineNo2;
        newNodeS2->child[0] = newNodeS3;

        /*antigo
        $$ = newDecNode(ArrDecK);
        $1->child[0] = $$; // Linking tipo_especificador node as child
        $$->attr.name = copyString($2->attr.name); 
        $$->attr.val = $4->attr.val;
        $$->type = $1->type;
        */
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
    tipo_especificador ID LPAREN params RPAREN composto_decl
    { 
        $$ = newDecNode(FunDecK);
        $$->attr.name = copyString($2->attr.name);
        $$->type = $1->type;
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
        $$ = newDecNode(VarDecK); // Adaptacao para o nó de declaracao
        $$->attr.name = copyString($2->attr.name);
        $$->type = $1->type;
    }
    | tipo_especificador ID LBRACKET RBRACKET
    {
        $$ = newDecNode(ArrDecK); // Adaptacao para o nó de declaracao de array
        $$->attr.name = copyString($2->attr.name);
        $$->type = $1->type;
    }
;

composto_decl:
    LBRACE local_declaracoes statement_lista RBRACE
        {
            $$ = newStmtNode(CompoundK);
            $$->child[0] = $2;
            $$->child[1] = $3;
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
    expressao_decl
    | composto_decl
    | selecao_decl
    | iteracao_decl
    | retorno_decl
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
    | simples_expressao
    ;

var:
    ID
        {
            $$ = newExpNode(IdK);
            $$->attr.name = copyString($1->attr.name);
        }
    | ID LBRACKET expressao RBRACKET
        {
            $$ = newExpNode(ArrK);
            $$->attr.name = copyString($1->attr.name);
            $$->child[0] = $3;
        }
    ;

simples_expressao:
    soma_expressao relacional soma_expressao
        {
            $$ = newExpNode(OpK);
            $$->attr.op = $2->attr.op;
            $$->child[0] = $1;
            $$->child[1] = $3;
        }
    | soma_expressao
    ;

relacional:
    LET { $$->attr.op = LET; }
    | LT { $$->attr.op = LT; }
    | BT { $$->attr.op = BT; }
    | BET { $$->attr.op = BET; }
    | EQUAL { $$->attr.op = EQUAL; }
    | DIF { $$->attr.op = DIF; }
    ;

soma_expressao:
    soma_expressao soma termo
        {
            $$ = newExpNode(OpK);
            $$->attr.op = $2->attr.op;
            $$->child[0] = $1;
            $$->child[1] = $3;
        }
    | termo
    ;

soma:
    PLUS { $$->attr.op = PLUS; }
    | MINUS { $$->attr.op = MINUS; }
    ;

termo:
    termo mult fator
        {
            $$ = newExpNode(OpK);
            $$->attr.op = $2->attr.op;
            $$->child[0] = $1;
            $$->child[1] = $3;
        }
    | fator
    ;

mult:
    TIMES { $$->attr.op = TIMES; }
    | OVER { $$->attr.op = OVER; }
    ;

fator:
    LPAREN expressao RPAREN { $$ = $2; }
    | var
    | ativacao
    | NUM
        {
            $$ = newExpNode(ConstK);
            $$->attr.val = $1->attr.val;
        }
    ;

ativacao:
    ID LPAREN args RPAREN
        {
            $$ = newExpNode(CallK);
            $$->attr.name = copyString($1->attr.name);
            $$->child[0] = $3;
        }
    ;

args:
    arg_lista
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
    | expressao
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

