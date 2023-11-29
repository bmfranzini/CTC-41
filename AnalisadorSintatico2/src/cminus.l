/****************************************************/
/* File: cminus.l                                   */
/* Lex specification for C-                         */
/* Project for CES41: Compiladores                  */
/****************************************************/
%option noyywrap 
/* 
  opção necessária para novas versões do flex
  limitação: não compila mais de um arquivo fonte de uma só vez (não precisamos disso)
  https://stackoverflow.com/questions/1480138/undefined-reference-to-yylex 
*/ 

%{
#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parser.h"
/* lexeme of identifier or reserved word */
char tokenString[MAXTOKENLEN+1];
char lastTokenString[MAXTOKENLEN+1];
static int yylex(void);
int currentLine = 0;
%}
%option noyywrap 

digit       [0-9]
number      {digit}+
letter      [a-zA-Z]
identifier  {letter}+
newline     (\n|\r\n)
whitespace  [ \t]+
%%
"if"            {return IF;}
"else"          {return ELSE;}
"int"           {return INT;}
"return"        {return RETURN;}
"void"          {return VOID;}
"while"         {return WHILE;}
"+"             {return PLUS;}
"-"             {return MINUS;}
"*"             {return TIMES;}
"/"             {return OVER;}
"<"             {return LT;}
"<="            {return LET;}
">"             {return BT;}
">="            {return BET;}
"=="            {return EQUAL;}
"!="            {return DIF;}
"="             {return ASSIGN;}
";"             {return SEMI;}
","             {return COMMA;}
"("             {return LPAREN;}
")"             {return RPAREN;}
"["             {return LBRACKET;}
"]"             {return RBRACKET;}
"{"             {return LBRACE;}
"}"             {return RBRACE;}
{number}        {return NUM;}
{identifier}    {return ID;}
{newline}       {lineno++;}
{whitespace}    {/* skip whitespace */}
"/*"            {
                  char c;
                  int nest_level = 1;
                  while (nest_level > 0) {
                    c = input();
                    if (c == EOF) break;
                    if (c == '\n') lineno++;
                    if (c == '*' && (c = input()) == '/') {
                      nest_level--;
                    } else if (c == '/' && (c = input()) == '*') {
                      nest_level++;
                    }
                  }
                }

.               {return ERROR;}
%%
TokenType getToken(void)
{ 
  static int firstTime = TRUE;
  TokenType currentToken;

  if (firstTime)
  { 
    firstTime = FALSE;
    lineno++;
    yyin = source;
    yyout = listing;
  }

  currentToken = yylex();
  strncpy(tokenString, yytext, MAXTOKENLEN);
  while (lineno != currentLine) {
    if (lines[currentLine] != NULL)
      fprintf(listing, "%d: %s", currentLine+1, lines[currentLine]);
    else
      fprintf(listing, "%d: \n", currentLine+1);
    currentLine++;
  }



  if (lines[lineno-1] == '\n') {
    fprintf(listing, "%d: ", lineno);
  }

  if (TraceScan)
  {
    fprintf(listing, "\t%d: ", lineno);
    printToken(currentToken, tokenString);
  }

  return currentToken;
}