/****************************************************/
/* File: symtab.h                                   */
/* Symbol table interface for the TINY compiler     */
/* (allows only one symbol table)                   */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#ifndef _SYMTAB_H_
#define _SYMTAB_H_

/* Procedure st_insert inserts line numbers and
 * memory locations into the symbol table
 * loc = memory location is inserted only the
 * first time, otherwise ignored
 */
void init_hashTable();
//void st_insert( char * name, int lineno, int loc );
char * st_lookupScopeType( char * name, char * scope, char * type );
int st_lookupScope ( char * name, char * scope, char * type );

void st_insert( char * name, char * scope, char * IdType, char * DataType, int lineno, char * type );

/* Function st_lookup returns the memory 
 * location of a variable or -1 if not found
 */
int st_lookup ( char * name );

char * find_type(char *name, int line);

/* Procedure printSymTab prints a formatted 
 * list of the symbol table contents 
 */
int st_lookupFunDecK ( char * name, char * scope);
void printSymTab();

#endif
