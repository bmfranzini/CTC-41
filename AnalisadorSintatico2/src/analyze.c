/****************************************************/
/* File: analyze.c                                  */
/* Semantic analyzer implementation                 */
/* for the TINY compiler                            */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include "globals.h"
#include "symtab.h"
#include "analyze.h"
#include "util.h"

/* counter for variable memory locations */
static int location = 0;
StackScope stackScope;
/* Procedure traverse is a generic recursive 
 * syntax tree traversal routine:
 * it applies preProc in preorder and postProc 
 * in postorder to tree pointed to by t
 */
static void traverse( TreeNode * t,
               void (* preProc) (TreeNode *),
               void (* postProc) (TreeNode *) )
{ if (t != NULL)
  { preProc(t);
    { int i;
      for (i=0; i < MAXCHILDREN; i++)
        traverse(t->child[i],preProc,postProc);
    }
    postProc(t);
    traverse(t->sibling,preProc,postProc);
  }
}

/* nullProc is a do-nothing procedure to 
 * generate preorder-only or postorder-only
 * traversals from traverse
 */
static void nullProc(TreeNode * t)
{ 
  if (t==NULL) return;
  else {
    switch (t->nodekind)
    {
        case DecK: 
            switch (t->kind.dec)
            { 
                case FunDecK:
                    if (!isEmptyScope()){
                        popScope();
                    } 
                    break;
                default:
                    break;
            }
    }
    return;
  }
}

/* Procedure insertNode inserts 
 * identifiers stored in t into 
 * the symbol table 
 */
static void insertNode(TreeNode * t)
{
    char* scope = "";
    char* fun = "fun";
    char* var = "var";
    char* array = "array";
    char* voidType = "void";
    char* intType = "int";
    char *FunKType = "FunK";
    char *OpKType = "OpK";
    char *ConstKType = "ConstK";
    char *IdKType = "IdK"; 
    char *VarKType = "VarK"; 
    char *ArrKType = "ArrK";
    char *DeclarationKType = "DeclarationK";
    char *VarDecKType = "VarDecK";
    char *FunDecKType = "FunDecK";
    char *ParamKType = "ParamK";
    char *ArrDecKType = "ArrDecK";

    switch (t->nodekind)
    {

        case ExpK:
        //void st_insert( char * name, char * scope, char * IdType, char * DataType, int lineno, int loc )
            switch (t->kind.exp)
            {
                case FunK:
                    // if(t->type == Void){
                    //     st_insert(t->attr.name, scope, fun, voidType, t->lineno, FunKType);
                    //     // if (isEmptyScope()){
                    //     //     st_insert(t->attr.name, scope, fun, voidType, t->lineno, 0);
                    //     // }
                    //     // else{
                    //     //     st_insert(t->attr.name, topScope(), fun, voidType, t->lineno, 0);
                    //     // }
                    // }
                    // else {
                    //     if (isEmptyScope()){
                    //         st_insert(t->attr.name, scope, fun, intType, t->lineno, FunKType);
                    //     }
                    //     else{
                    //         st_insert(t->attr.name, topScope(), fun, intType, t->lineno, FunKType);
                    //     }
                    // }
                    //     // st_insert(t->attr.name, scope, fun, intType, t->lineno, 0);
                    // break;

                    /*pizao aqui*/
                    char* auxFunType;
                    if (t->type == Integer){
                        auxFunType = "int";
                    }
                    else {
                        auxFunType = "void";
                    }
                    if (isEmptyScope()){
                        st_insert(t->attr.name, scope, fun, auxFunType, t->lineno, FunKType);
                    }
                    else{
                        
                        int auxScope = st_lookupScope(t->attr.name, topScope(), FunDecKType);
                        char * varKScope = "";
                        if (auxScope == 0) {
                            varKScope = topScope();
                        }
                        else if (auxScope == -1) {
                            auxScope = st_lookupScope(t->attr.name, topScope2(), FunDecKType);
                            if (auxScope == -1) { //nao achou declaracao e ta usando vark, erro
                                pc("\nSemantic error at line %d: '%s' was not declared in this scope\n\n", t->lineno, t->attr.name);
                                //pizao
                                Error = TRUE;
                                break;
                            }
                            else {
                                auxFunType = st_lookupScopeType(t->attr.name, topScope2(), FunDecKType);
                                varKScope = topScope2();
                               //pc("\nauxfuntype %s:\n", auxFunType);
                               //pc("\nattr name %s:\n", t->attr.name);
                            }
                            
                        }
                        st_insert(t->attr.name, varKScope, fun, auxFunType, t->lineno, FunKType);
                    }
                    break;  
                    /*terminou pizao aqui*/                  

                case IdK:  // Presumindo que ArrK seja uma enum para arrays no C-
                    if (isEmptyScope()){
                        st_insert(t->attr.name, scope, var, intType, t->lineno, IdKType);
                    }
                    else{
                        st_insert(t->attr.name, topScope(), var, intType, t->lineno, IdKType);
                    }
                    break;
                case VarK:  // Presumindo que VarK seja uma enum para variáveis no C-
                    // st_insert(t->attr.name, scope, var, intType, t->lineno, 0);
                    
                    char* auxVarType;
                    if (t->type == Integer){
                        auxVarType = "int";
                    }
                    else {
                        auxVarType = "void";
                    }
                    if (isEmptyScope()){
                        st_insert(t->attr.name, scope, var, auxVarType, t->lineno, VarKType);
                    }
                    else{
                        
                        int auxScope = st_lookupScope(t->attr.name, topScope(), VarDecKType);
                        char * varKScope = "";
                        if (auxScope == 0) {
                            varKScope = topScope();
                        }
                        else if (auxScope == -1) {
                            auxScope = st_lookupScope(t->attr.name, topScope2(), VarDecKType);
                            if (auxScope == -1) { //nao achou declaracao e ta usando vark, erro
                                pc("\nSemantic error at line %d: '%s' was not declared in this scope\n\n", t->lineno, t->attr.name);
                                //pizao
                                Error = TRUE;
                                break;
                            }
                            else {
                                varKScope = topScope2();
                            }
                            
                        }
                        st_insert(t->attr.name, varKScope, var, auxVarType, t->lineno, VarKType);
                    }
                    break;
                case ArrK:
                    // st_insert(t->attr.name, scope, array, intType, t->lineno, 0);
                    char* auxArrType;
                    if (t->type == Integer){
                        auxArrType = "int";
                    }
                    else {
                        auxArrType = "void";
                    }
                    if (isEmptyScope()){
                        st_insert(t->attr.name, scope, array, auxArrType, t->lineno, ArrKType);
                    }
                    else{
                        int auxScope = st_lookupScope(t->attr.name, topScope(), ArrDecKType);
                        char * arrKScope = "";
                        if (auxScope == 0) {
                            arrKScope = topScope();
                        }
                        else if (auxScope == -1) {
                            auxScope = st_lookupScope(t->attr.name, topScope2(), ArrDecKType);
                            if (auxScope == -1) {
                                break;
                            }
                            else {
                                arrKScope = topScope2();
                            }
                            
                        }
                        st_insert(t->attr.name, topScope(), array, auxArrType, t->lineno, ArrKType);
                    }
                    break;
                default:
                    break;
            }
            break;
        case DecK: 
            switch (t->kind.dec)
            { 
                case FunDecK:
                    if(t->type == Void){ 
                        // st_insert(t->attr.name, topScope(), fun, voidType, t->lineno, 0);

                        if (isEmptyScope()){
                            int auxScope = st_lookupScope(t->attr.name, topScope(), FunDecKType);
                            if (auxScope == 0) {
                                pc("\nSemantic error at line %d: '%c' was already declared as a variable:\n\n", t->lineno, t->attr.name);
                                Error = TRUE;
                                break;
                            }
                            else {
                                st_insert(t->attr.name, scope, fun, voidType, t->lineno, FunDecKType);
                            }
                        }
                        else{
                            int auxScope = st_lookupScope(t->attr.name, topScope(), FunDecKType);
                            if (auxScope == 0) {
                                pc("\nSemantic error at line %d: '%c' was already declared as a variable:\n\n", t->lineno, t->attr.name);
                                Error = TRUE;
                                break;
                            }
                            else {
                                st_insert(t->attr.name, topScope(), fun, voidType, t->lineno, FunDecKType);
                            }
                        
                        }
                    }
                    else{
                        // st_insert(t->attr.name, topScope(), fun, intType, t->lineno, 0);
                        
                        if (isEmptyScope()){
                            st_insert(t->attr.name, scope, fun, intType, t->lineno, FunDecKType);
                        }
                        else{
                            st_insert(t->attr.name, topScope(), fun, intType, t->lineno, FunDecKType);
                        }
                    }    
                    pushScope(t->attr.name);
                    break;
                case VarDecK:  // Presumindo que VarK seja uma enum para variáveis no C-
                    char* auxType;
                    if (t->type == Integer){
                        auxType = "int";
                    }
                    else {
                        auxType = "void";
                    }
                    if (isEmptyScope()){
                        st_insert(t->attr.name, scope, var, auxType, t->lineno, VarDecKType);
                    }
                    // else{

                    //     int auxScope = st_lookupScope(t->attr.name, topScope(), VarDecKType);
                    //     if (auxScope == 0) {
                    //         pc("\nSemantic error at line %d: '%s' was already declared as a variable\n\n", t->lineno, t->attr.name);
                    //         break;
                    //     }
                    //     else {
                    //         st_insert(t->attr.name, topScope(), var, auxType, t->lineno, VarDecKType);
                    //     }
                    //     //st_insert(t->attr.name, topScope(), var, auxType, t->lineno, VarDecKType);
                    // }
                    // break;

                    /*pizao aqui. para o caso ser7 variable name used for function*/
                    else {
                        int auxScope = st_lookupFunDecK(t->attr.name, topScope2());
                        //pc("\n auxscope do %s na linha %d = %d\n",t->attr.name, t->lineno, auxScope);
                        //pc("\n topScope2 do %s na linha %d = %s\n",t->attr.name, t->lineno, topScope2());
                        if (auxScope == 0) { //achou declaracao de funcao, erro
                            pc("Semantic error at line %d: '%s' was already declared as a function\n", t->lineno, t->attr.name);
                            //pizao
                            Error = TRUE;
                            break;
                        }

                        auxScope = st_lookupScope(t->attr.name, topScope(), VarDecKType);
                        if (auxScope == 0) {
                            pc("\nSemantic error at line %d: '%s' was already declared as a variable\n\n", t->lineno, t->attr.name);
                            Error = TRUE;
                            break;
                        }
                        else {
                            st_insert(t->attr.name, topScope(), var, auxType, t->lineno, VarDecKType);
                        }
                        //st_insert(t->attr.name, topScope(), var, auxType, t->lineno, VarDecKType);
                    }
                    break;
                    /*pizao termina*/


                case ArrDecK:
                    if (isEmptyScope()){
                        st_insert(t->attr.name, scope, array, intType, t->lineno, ArrDecKType);
                    }
                    else{
                        st_insert(t->attr.name, topScope(), array, intType, t->lineno, ArrDecKType);
                    }
                    break;
                default:
                    break;
    }
}
}

/* Function buildSymtab constructs the symbol 
 * table by preorder traversal of the syntax tree
 */
void buildSymtab(TreeNode * syntaxTree)
{ 
  init_hashTable();   
  traverse(syntaxTree,insertNode,nullProc);
  if (TraceAnalyze)
  { pc("\nSymbol table:\n\n");
    printSymTab();
  }
}

static void typeError(TreeNode * t, char * message)
{ pce("Type error at line %d: %s\n",t->lineno,message);
  Error = TRUE;
}

/* Procedure checkNode performs
 * type checking at a single tree node
 */
static void checkNode(TreeNode * t)
{
    switch (t->nodekind)
    {
        case ExpK:
            switch (t->kind.exp)
            {
                case OpK:
                    if ((t->child[0]->type != Integer) || (t->child[1]->type != Integer))
                        typeError(t, "Op applied to non-integer");
                    t->type = Integer;
                    break;

                case ConstK:
                    t->type = Integer;
                    break;

                case IdK:
                case VarK:
                    t->type = Integer;
                    break;

                case ArrK:
                    t->type = Integer;
                    break;

                case FunK:
                    break;

                default:
                    break;
            }
            break;

        case StmtK:
            switch (t->kind.stmt)
            {
                case IfK:
                case WhileK:
                    if (t->child[0]->type != Integer)
                        typeError(t->child[0], "Conditional test is not Integer");
                    break;

                case AssignK:
                    if (t->child[0]->type == Void) {
                        //typeError(t->child[0], "assignment of non-integer value");
                        pc("\nSemantic error at line %d: invalid use of void expression\n\n", t->child[0]->lineno);//, t->child[0]->type, t->child[1]->type);
                        Error = TRUE;
                    } else if (t->child[1]->type == Void) {
                           if (strcmp(find_type(t->child[1]->attr.name, t->child[1]->lineno), "void") == 0) {
                            //pc("saida do find_type de nome %s: %s", t->child[1]->attr.name, find_type(t->child[1]->attr.name, t->child[1]->lineno));
                            pc("\nSemantic error at line %d: invalid use of void expression\n\n", t->child[1]->lineno);
                            Error = TRUE;
                           }
                    }

                    break;

                case ReturnK:

                    break;

                default:
                    break;
            }
            break;

        case DecK:
            switch (t->kind.dec)
            {
                //case DeclarationK:
                case VarDecK:
                    if(t->type != Integer)
                        pc("\nSemantic error at line %d: variable declared void\n\n", t->lineno);
                    break;
                case ArrDecK:
                    if(t->type != Integer)
                        pc("\nSemantic error at line %d: variable declared void\n\n", t->lineno);
                    break;

                case FunDecK:
                    break;

                case ParamK:
                    t->type = Integer;
                    break;

                default:
                    break;
            }
            break;

        default:
            break;
    }
}



/* Procedure typeCheck performs type checking 
 * by a postorder syntax tree traversal
 */
void typeCheck(TreeNode * syntaxTree)
{ traverse(syntaxTree,nullProc,checkNode);
}

int mainCheck(TreeNode * syntaxTree)
{ 
    char *mainStr = "main";
    return st_lookup(mainStr);
}