#include "parser.h"

int yyerror(Parser &parser, const char *s) {
    extern char *yytext;
    std::cout << "[Error]: " << s << ". Current Text: " << yytext << std::endl;
    return 0;
}
