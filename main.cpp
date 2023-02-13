#include "Driver.hpp"

int main() {
    Driver driver;
    extern int yyparse(Driver &driver);

    yyparse(driver);

    //node->print();
    driver.ast.root.printTree(0);
}
