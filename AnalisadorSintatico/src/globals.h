/****************************************************/
/* File: globals.h                                  */
/* Global types and vars for TINY compiler          */
/* must come before other include files             */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "log.h"

#ifndef YYPARSER

/* the name of the following file may change */
//#include "tiny.tab.h"
#include "parser.h"

/* ENDFILE is implicitly defined by Yacc/Bison,
 * and not included in the tab.h file
 */
#define ENDFILE 0

#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

/* MAXRESERVED = the number of reserved words */
#define MAXRESERVED 8

typedef int TokenType; 

// typedef enum 
//     /* book-keeping tokens */
//    {ENDFILE, ERROR,
//     /* reserved words */
//     IF, ELSE, INT, RETURN, VOID, WHILE,
//     /* multicharacter tokens */
//     PLUS, MINUS, TIMES, OVER, EQUAL, DIF, LT, LET, BT, BET,
//     /* special symbols */
//     ASSIGN, SEMI, COMMA, LPAREN, RPAREN, LBRACKET, RBRACKET, LBRACE, RBRACE, NUM, ID
//    } TokenType;

extern FILE* source; /* source code text file */
extern FILE* listing; /* listing output text file */
extern FILE* code; /* code text file for TM simulator */

extern int lineno; /* source line number for listing */
extern int currentLine;
extern int line_count;
//extern char lines[50][50];
extern char *lines[100]; // Matriz de ponteiros para linhas

/**************************************************/
/***********   Syntax tree for parsing ************/
/**************************************************/

typedef enum {StmtK, ExpK, DecK} NodeKind; // Adding DecK for Declarations
typedef enum {IfK, WhileK, AssignK, ReturnK, CallK, CompoundK} StmtKind; // Adjusted kinds
typedef enum {OpK, ConstK, IdK, VarK, ArrK, FunK} ExpKind; // Expanded expression kinds
typedef enum {DeclarationK, VarDecK, FunDecK, ParamK, ArrDecK} DecKind; // Added declaration kinds

typedef enum {Void, Integer} ExpType; // Removed Boolean

#define MAXCHILDREN 3

typedef struct treeNode
{
    struct treeNode *child[MAXCHILDREN];
    struct treeNode *sibling;
    int lineno;
    NodeKind nodekind;
    union { 
        StmtKind stmt; 
        ExpKind exp; 
        DecKind dec;   // Adicionando DecKind ao kind
    } kind;
    union { 
        TokenType op;
        int val;
        char *name;
        // Aqui você pode adicionar mais campos, se declarações tiverem atributos adicionais
    } attr;
    ExpType type; /* for type checking of exps */
} TreeNode;
/**************************************************/
/***********   Flags for tracing       ************/
/**************************************************/

/* EchoSource = TRUE causes the source program to
 * be echoed to the listing file with line numbers
 * during parsing
 */
extern int EchoSource;

/* TraceScan = TRUE causes token information to be
 * printed to the listing file as each token is
 * recognized by the scanner
 */
extern int TraceScan;

/* TraceParse = TRUE causes the syntax tree to be
 * printed to the listing file in linearized form
 * (using indents for children)
 */
extern int TraceParse;

/* TraceAnalyze = TRUE causes symbol table inserts
 * and lookups to be reported to the listing file
 */
extern int TraceAnalyze;

/* TraceCode = TRUE causes comments to be written
 * to the TM code file as code is generated
 */
extern int TraceCode;

/* Error = TRUE prevents further passes if an error occurs */
extern int Error; 
#endif
