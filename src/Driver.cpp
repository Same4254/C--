#include "Driver.hpp"

int yyerror(Driver &driver, const char *s) {
    extern char *yytext;
    std::cout << "[Error]: " << s << ". Current Text: " << yytext << std::endl;
    exit(1);
    return 0;
}
