/****************************************************/
/* File: symtab.c                                   */
/* Symbol table implementation for the TINY compiler*/
/* (allows only one symbol table)                   */
/* Symbol table is implemented as a chained         */
/* hash table                                       */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "symtab.h"
#include "globals.h"

/* SIZE is the size of the hash table */
#define SIZE 211

/* SHIFT is the power of two used as multiplier
   in hash function  */
#define SHIFT 4

/* the hash function */
static int hash ( char * key )
{ int temp = 0;
  int i = 0;
  while (key[i] != '\0')
  { temp = ((temp << SHIFT) + key[i]) % SIZE;
    ++i;
  }
  return temp;
}

/* the list of line numbers of the source 
 * code in which a variable is referenced
 */
typedef struct LineListRec
   { int lineno;
     struct LineListRec * next;
   } * LineList;
/* The record in the bucket lists for
 * each variable, including name, 
 * assigned memory location, and
 * the list of line numbers in which
 * it appears in the source code
 */
typedef struct BucketListRec
   { char * name;
     char * scope;
     char * IdType;
     char * DataType;
     LineList lines;
     char * type ; /* memory location for variable */
     struct BucketListRec * next;
   } * BucketList;

/* the hash table */
static BucketList hashTable[SIZE];

/* Procedure st_insert inserts line numbers and
 * memory locations into the symbol table
 * loc = memory location is inserted only the
 * first time, otherwise ignored
 */

void init_hashTable(){
  char *input = "input";
  int h = hash(input);
  BucketList l = hashTable[h];
  l = (BucketList) malloc(sizeof(struct BucketListRec));
  l->name = input;
  l->scope = "";
  l->IdType = "fun";
  l->DataType = "int";
  l->lines = (LineList) malloc(sizeof(struct LineListRec));
  l->lines->lineno = -1;
  l->type = "";
  l->lines->next = NULL;
  l->next = hashTable[h];
  hashTable[h] = l;
  char *output = "output";
  int h_out = hash(output);
  BucketList l_out = hashTable[h_out];
  l_out = (BucketList) malloc(sizeof(struct BucketListRec));
  l_out->name = output;
  l_out->scope = "";
  l_out->IdType = "fun";
  l_out->DataType = "void";
  l_out->lines = (LineList) malloc(sizeof(struct LineListRec));
  l_out->lines->lineno = -1;
  l_out->type = "";
  l_out->lines->next = NULL;
  l_out->next = hashTable[h_out];
  hashTable[h_out] = l_out;
}
void st_insert( char * name, char * scope, char * IdType, char * DataType, int lineno, char * type )
{ 
  int h = hash(name);
  BucketList l =  hashTable[h];
  char *input = "input";
  char *output = "output";
  char *vazio = "";
  if (strcmp(name, input) !=0 && strcmp(name, output) != 0){
    while ((l != NULL) && ((strcmp(name, l->name) != 0) || ((strcmp(name, l->name) == 0) && strcmp(scope, l->scope) != 0 && (strcmp(vazio, l->scope) != 0 || (l->IdType != IdType)))))//&& (l->IdType != IdType)
      l = l->next;
  }
  else {
    while ((l != NULL) && ((strcmp(name, l->name) != 0)))
      l = l->next;
  }
  if (l == NULL) /* variable not yet in table */
  { l = (BucketList) malloc(sizeof(struct BucketListRec));
    l->name = name;
    l->scope = scope;
    l->IdType = IdType;
    l->DataType = DataType;
    l->lines = (LineList) malloc(sizeof(struct LineListRec));
    l->lines->lineno = lineno;
    l->type = type;
    l->lines->next = NULL;
    l->next = hashTable[h];
    hashTable[h] = l; }
  else /* found in table, so just add line number */
  { LineList t = l->lines;
    while (t->next != NULL) t = t->next;

    if(t->lineno != lineno){
      t->next = (LineList) malloc(sizeof(struct LineListRec));
      t->next->lineno = lineno;
      t->next->next = NULL;
    }
  }
} /* st_insert */

/* Function st_lookup returns the memory 
 * location of a variable or -1 if not found
 */
int st_lookup ( char * name )
{ int h = hash(name);
  BucketList l =  hashTable[h];
  while ((l != NULL) && (strcmp(name,l->name) != 0))
    l = l->next;
  if (l == NULL) return -1;
  else return 0;
}

char * find_type(char *name, int line) {
  int h = hash(name);
  BucketList l =  hashTable[h];
  bool foundName = FALSE;
  bool foundLine = FALSE;
  //while ((l != NULL) && ((strcmp(name,l->name) != 0) || (strcmp(scope,l->scope) != 0))){// || (compareType != 0))){//|| (strcmp(type,l->type) != 0)
  //while (!((l == NULL) || ((strcmp(name,l->name) == 0))) ){
  while (!((l == NULL) || (foundName && foundLine))) {
    foundName = FALSE;
    if (strcmp(name,l->name) == 0) {
      LineList temp = l->lines;
      while (temp != NULL && temp->lineno != line) {
        temp = temp->next;
      }
      if (temp != NULL && temp->lineno == line) {
        foundLine = TRUE;
        foundName = TRUE;
        return l->DataType;
      }
      
    }
    l = l->next;
    //pc("loop\n");
  }
  if (l == NULL) return "bizarro";
  else {
    return l->DataType;
  }
}

char* st_lookupScopeType( char * name, char * scope, char * type )
{ int h = hash(name);
  BucketList l =  hashTable[h];

  //while ((l != NULL) && ((strcmp(name,l->name) != 0) || (strcmp(scope,l->scope) != 0))){// || (compareType != 0))){//|| (strcmp(type,l->type) != 0)
  while (!((l == NULL) || ((strcmp(name,l->name) == 0) && (strcmp(scope,l->scope) == 0)))){
    l = l->next;
  }
  if (l == NULL) return "bizarro2";
  else {
    return l->DataType;
  }
}

int st_lookupScope ( char * name, char * scope, char * type )
{ int h = hash(name);
  BucketList l =  hashTable[h];
  // int compareType = 0;
  // if (strcmp(type, "FunDecK") == 0) {
  //   compareType = strcmp(type,l->type);
  // }
  //while ((l != NULL) && ((strcmp(name,l->name) != 0) || (strcmp(scope,l->scope) != 0))){// || (compareType != 0))){//|| (strcmp(type,l->type) != 0)
  while (!((l == NULL) || ((strcmp(name,l->name) == 0) && (strcmp(scope,l->scope) == 0)))){
    l = l->next;
    // if (l != NULL && strcmp(type, "FunDecK") == 0) {
    //   compareType = strcmp(type,l->type);
    // }
  }
  if (l == NULL) return -1;
  else {
    
    return 0;
  }
}

int st_lookupFunDecK ( char * name, char * scope)
{ int h = hash(name);
  BucketList l =  hashTable[h];
  while (!((l == NULL) || ((strcmp(name,l->name) == 0) && (strcmp(scope,l->scope) == 0)))){
    l = l->next;
  }
  if (l == NULL ) return -1;
  else if (strcmp(l->type, "FunDecK") == 0){
    return 0;
  }
  else {
    return -1;
  }
}
/* Procedure printSymTab prints a formatted 
 * list of the symbol table contents 
 */
void printSymTab()
{ int i;
  pc("Variable Name  Scope     ID Type  Data Type  Line Numbers \n");
  pc("-------------  --------  -------  ---------  -------------------------\n");
  for (i=0;i<SIZE;++i)
  { if (hashTable[i] != NULL)
    { BucketList l = hashTable[i];
      while (l != NULL)
      { LineList t = l->lines;
        pc("%-14s ",l->name);
        pc("%-8s  ",l->scope);
        pc("%-7s  ",l->IdType);
        pc("%-9s  ",l->DataType);
        while (t != NULL)
        { 
          if (t->lineno != -1){
            pc("%4d ",t->lineno);
          }
          t = t->next;
        }
        pc("\n");
        l = l->next;
      }
    }
  }
} /* printSymTab */
