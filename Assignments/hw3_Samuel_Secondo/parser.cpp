#include "parser.h"

int yyerror(Parser *parser, const char *s) {
    std::cout << "[Error]: " << s << std::endl;
	return 0;
}
