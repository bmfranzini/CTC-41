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

/* counter for variable memory locations */
static int location = 0;

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
{ if (t==NULL) return;
  else return;
}

/* Procedure insertNode inserts 
 * identifiers stored in t into 
 * the symbol table 
 */
static void insertNode(TreeNode * t)
{
    switch (t->nodekind)
    {
        case StmtK:
            switch (t->kind.stmt)
            {
                case AssignK:
                    if (st_lookup(t->attr.name) == -1)
                        st_insert(t->attr.name, t->lineno, location++);
                    else
                        st_insert(t->attr.name, t->lineno, 0);
                    break;
                
                default:
                    break;
            }
            break;

        case ExpK:
            switch (t->kind.exp)
            {
                case IdK:
                case VarK:  // Presumindo que VarK seja uma enum para variáveis no C-
                case ArrK:  // Presumindo que ArrK seja uma enum para arrays no C-
                    if (st_lookup(t->attr.name) == -1)
                        st_insert(t->attr.name, t->lineno, location++);
                    else
                        st_insert(t->attr.name, t->lineno, 0);
                    break;
                default:
                    break;
            }
            break;
        case DecK: 
            switch (t->kind.dec)
            {
                case FunK:
                case VarDecK:
                case ArrDecK:
                    if (st_lookup(t->attr.name) == -1)
                        st_insert(t->attr.name, t->lineno, location++);
                    else
                        st_insert(t->attr.name, t->lineno, 0);
                    break;

                default:
                    break;
            }
            break;

        default:
            break;
    }
}

/* Function buildSymtab constructs the symbol 
 * table by preorder traversal of the syntax tree
 */
void buildSymtab(TreeNode * syntaxTree)
{ traverse(syntaxTree,insertNode,nullProc);
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
                    if (t->child[0]->type != Integer)
                        typeError(t->child[0], "assignment of non-integer value");
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
                case DeclarationK:
                case VarDecK:
                case ArrDecK:
                    t->type = Integer;
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
