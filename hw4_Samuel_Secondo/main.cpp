#include "parser.h"

int main() {
    Parser parser;
    extern int yyparse(Parser &parser);

    yyparse(parser);

    //node->print();
    parser.ast.root.printTree(0);
}
