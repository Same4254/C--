#include "Driver.hpp"

int main() {
    Driver driver;
    extern int yyparse(Driver &driver);

    yyparse(driver);

    //node->print();
    driver.ast.root.printTree(0);

    Environment env;
    driver.ast.root.pass_0(env);
    driver.ast.root.pass_1(env);
    driver.ast.root.pass_2(env);
}
