/****************************************************/
/* File: util.c                                     */
/* Utility function implementation                  */
/* for the TINY compiler                            */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include "globals.h"
#include "util.h"

/* Procedure printToken prints a token 
 * and its lexeme to the listing file
 */
void printToken( TokenType token, const char* tokenString )
{ switch (token)
  { case IF:
    case ELSE:
    case INT:
    case RETURN:
    case VOID:
    case WHILE:
    fprintf(listing,
         "reserved word: %s\n",tokenString);
      break;
    case PLUS: fprintf(listing,"+\n"); break;
    case MINUS: fprintf(listing,"-\n"); break;
    case TIMES: fprintf(listing,"*\n"); break;
    case OVER: fprintf(listing,"/\n"); break;
    case LT: fprintf(listing,"<\n"); break;
    case LET: fprintf(listing,"<=\n"); break;
    case BT: fprintf(listing,">\n"); break;
    case BET: fprintf(listing,">=\n"); break;
    case EQUAL: fprintf(listing,"==\n"); break;
    case DIF: fprintf(listing,"!=\n"); break;
    case ASSIGN: fprintf(listing,"=\n"); break;
    case SEMI: fprintf(listing,";\n"); break;
    case COMMA: fprintf(listing,",\n"); break;
    case LPAREN: fprintf(listing,"(\n"); break;
    case RPAREN: fprintf(listing,")\n"); break;
    case LBRACKET: fprintf(listing,"[\n"); break;
    case RBRACKET: fprintf(listing,"]\n"); break;
    case LBRACE: fprintf(listing,"{\n"); break;
    case RBRACE: fprintf(listing,"}\n"); break;
    case ENDFILE: fprintf(listing,"EOF\n"); break;
    case NUM:
      fprintf(listing,
          "NUM, val= %s\n",tokenString);
      break;
    case ID:
      fprintf(listing,
          "ID, name= %s\n",tokenString);
      break;
    case ERROR:
      fprintf(listing,
          "ERROR: %s\n",tokenString);
      break;

    default: /* should never happen */
      fprintf(listing,"Unknown token: %d\n",token);
  }
}

/* Function newStmtNode creates a new statement
 * node for syntax tree construction
 */
TreeNode * newStmtNode(StmtKind kind)
{ TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
  int i;
  if (t==NULL)
    fprintf(listing,"Out of memory error at line %d\n",lineno);
  else {
    for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
    t->sibling = NULL;
    t->nodekind = StmtK;
    t->kind.stmt = kind;
    t->lineno = lineno;
  }
  return t;
}

/* Function newExpNode creates a new expression 
 * node for syntax tree construction
 */
TreeNode * newExpNode(ExpKind kind)
{ TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
  int i;
  if (t==NULL)
    fprintf(listing,"Out of memory error at line %d\n",lineno);
  else {
    for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
    t->sibling = NULL;
    t->nodekind = ExpK;
    t->kind.exp = kind;
    t->lineno = lineno;
    t->type = Void;
  }
  return t;
}

TreeNode * newDecNode(DecKind kind)
{
    TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
    int i;
    if (t == NULL)
        pce("Out of memory error at line %d\n", lineno);
    else 
    {
        for (i = 0; i < MAXCHILDREN; i++) t->child[i] = NULL;
        t->sibling = NULL;
        t->nodekind = DecK;
        t->kind.dec = kind;
        t->lineno = lineno;
    }
    return t;
}

/* Function copyString allocates and makes a new
 * copy of an existing string
 */
char * copyString(char * s)
{ 
  int n;
  char * t;
  if (s==NULL) return NULL;
  n = strlen(s)+1;
  t = malloc(n);
  if (t==NULL)
    fprintf(listing,"Out of memory error at line %d\n",lineno);
  else strcpy(t,s);
  return t;
}

/* Variable indentno is used by printTree to
 * store current number of spaces to indent
 */
static int indentno = 0;

/* macros to increase/decrease indentation */
#define INDENT indentno+=2
#define UNINDENT indentno-=2

/* printSpaces indents by printing spaces */
static void printSpaces(void)
{ int i;
  for (i=0;i<indentno;i++)
    fprintf(listing," ");
}

/* procedure printTree prints a syntax tree to the 
 * listing file using indentation to indicate subtrees
 */
void printTree(TreeNode *tree)
{
    int i;
    INDENT;

    while (tree != NULL) 
    {
        printSpaces();

        if (tree->nodekind == StmtK) 
        {
            switch (tree->kind.stmt) 
            {
                case IfK:
                    fprintf(listing, "If\n");
                    break;
                case AssignK:
                    fprintf(listing, "Assign:\n");
                    break;
                case WhileK:
                    fprintf(listing, "While\n");
                    break;
                case ReturnK:
                    fprintf(listing, "Return\n");
                    break;
                default:
                    fprintf(listing, "Unknown StmtNode kind\n");
                    break;
            }
        } 
        else if (tree->nodekind == ExpK) 
        {
            switch (tree->kind.exp) 
            {
                case OpK:
                    fprintf(listing, "Op: %s\n", tree->attr.name);
                    // printToken(tree->attr.op, "\0");
                    break;
                case ConstK:
                    fprintf(listing, "Const: %d\n", tree->attr.val);
                    break;
                case IdK:
                    fprintf(listing, "Id: %s\n", tree->attr.name);
                    break;
                case VarK:
                    fprintf(listing, "Id: %s\n", tree->attr.name);
                    break;
                case FunK:
                    fprintf(listing, "Activation: %s\n", tree->attr.name);
                    break; 
                // Adicione aqui outros cases para os tipos ExpKind se necessário
                default:
                    fprintf(listing, "Unknown ExpNode kind\n");
                    break;
            }
        } 
        else if (tree->nodekind == DecK) 
        {
            switch (tree->kind.dec) 
            {
                case VarDecK:
                    fprintf(listing, "Id: %s\n", tree->attr.name);
                    break;
                case ArrDecK:
                    fprintf(listing, "Id: %s\n", tree->attr.name);
                    break;
                case FunDecK:
                    fprintf(listing, "Id: %s\n", tree->attr.name);
                    break;
                case ParamK:
                    fprintf(listing, "Parameter: %s\n", tree->attr.name);
                    break;
                case DeclarationK:
                    fprintf(listing, "Type: %s\n", tree->attr.name);
                    break;
                default:
                    fprintf(listing, "Unknown DecNode kind\n");
                    break;
            }
        } 
        else 
        {
            fprintf(listing, "Unknown node kind\n");
        }

        for (i = 0; i < MAXCHILDREN; i++)
            printTree(tree->child[i]);

        tree = tree->sibling;
    }
    UNINDENT;
}

void initStackChar() {
    stackSavedString.top = -1;
}

int isFullChar() {
    return stackSavedString.top == 100 - 1;
}

int isEmptyChar() {
    return stackSavedString.top == -1;
}

void pushChar(char *item) {
    if (!isFullChar()) {
        stackSavedString.items[++stackSavedString.top] = item;
    }
}

char* popChar( ) {
    if (!isEmptyChar()) {
        return stackSavedString.items[stackSavedString.top--];
    }
    return NULL;
}

void initStackInt() {
    stackLineno.top = -1;
}

int isFullInt() {
    return stackLineno.top == 100 - 1;
}

int isEmptyInt() {
    return stackLineno.top == -1;
}

void pushInt(int item) {
    if (!isFullInt()) {
        stackLineno.items[++stackLineno.top] = item;
    }
    else
     stackLineno.items[++stackLineno.top] = item;
}

int popInt() {
    if (!isEmptyInt()) {
        return stackLineno.items[stackLineno.top--];
    }
    return -1;
}

void initStackScope() {
    stackScope.top = -1;
}

int isFullScope() {
    return stackScope.top == 100 - 1;
}

int isEmptyScope() {
    return stackScope.top == -1;
}

void pushScope(char *item) {
    if (!isFullScope()) {
        stackScope.items[++stackScope.top] = item;
    }
}

char* popScope( ) {
    if (!isEmptyScope()) {
        return stackScope.items[stackScope.top--];
    }
    return NULL;
}

char* topScope( ) {
    if (!isEmptyScope()) {
        return stackScope.items[stackScope.top];
    }
    return NULL;
}