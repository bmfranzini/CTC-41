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

                // Remove o case ReadK, pois C- pode não tê-lo.
                // case ReadK:
                //     ...

                // Adicione casos adicionais se C- tiver outras instruções que requerem inserção na tabela de símbolos.
                
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

                // Adicione lógica para outros tipos de expressões, se necessário.

                default:
                    break;
            }
            break;
        case DecK:  // Presumindo que DecK seja uma enum para declarações no C-
            switch (t->kind.dec)
            {
                case FunK:    // Para funções.
                case VarDecK: // Para declarações de variáveis.
                case ArrDecK: // Para declarações de arrays.
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
                    t->type = Integer; // Assumindo que todas as operações retornam inteiros.
                    break;

                case ConstK:
                    t->type = Integer;
                    break;

                case IdK:
                case VarK:
                    t->type = Integer; // Se as variáveis e identificadores forem sempre inteiros em C-
                    break;

                case ArrK:
                    t->type = Integer; // Arrays em C- devem ser do tipo inteiro.
                    break;

                case FunK:
                    // Como as funções em C- podem ter tipo Void ou Integer, 
                    // pode ser necessário realizar verificações adicionais aqui para determinar o tipo.
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
                    if (t->child[0]->type != Integer)  // Considerando que em C- as condições são inteiros.
                        typeError(t->child[0], "Conditional test is not Integer");
                    break;

                case AssignK:
                    if (t->child[0]->type != Integer)
                        typeError(t->child[0], "assignment of non-integer value");
                    break;

                case ReturnK:
                    // Pode ser necessário adicionar verificações adicionais para as instruções de retorno,
                    // dependendo de como as funções são definidas em C-.
                    break;

                case CallK:
                    // Pode ser necessário adicionar verificações para chamadas de função.
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
                    t->type = Integer; // Supondo que todas as declarações sejam de inteiros.
                    break;

                case FunDecK:
                    // O tipo da função dependerá de sua declaração em C-.
                    // Pode ser Integer ou Void.
                    break;

                case ParamK:
                    t->type = Integer; // Supondo que todos os parâmetros sejam inteiros.
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
