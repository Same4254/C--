#include "parser.h"

int main() {
    Parser parser;
	extern int yyparse(Parser *parser);

    yyparse(&parser);

    ASTNode *node = parser.ast.GetRootNode();
    node->print();
}
