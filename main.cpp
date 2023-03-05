#include "Driver.hpp"
#include "GeneratedCode.hpp"

int main() {
    Driver driver;
    extern int yyparse(Driver &driver);

    yyparse(driver);

    //node->print();
    std::cout << "---------- ABSTRACT SYNTAX TREE ----------" << std::endl;
    driver.ast.root.printTree(0);

    std::cout << std::endl;
    std::cout << "---------- SEMANTIC ANALYSIS ----------" << std::endl;
    Environment env;

    std::cout << "----- Pass 0 -----" << std::endl;
    driver.ast.root.pass_0(env);

    std::cout << "----- Pass 1 -----" << std::endl;
    driver.ast.root.pass_1(env);

    std::cout << "----- Pass 2 -----" << std::endl;
    driver.ast.root.pass_2(env);

    std::cout << "----- Pass 3 -----" << std::endl;
    driver.ast.root.pass_3(env);
    std::cout << "Passed Semantic Analysis!!" << std::endl;

    std::cout << "---------- Code Generation ----------" << std::endl;
    GeneratedCode code;
    driver.ast.root.genCode(env, code);

    code.getModule().print(llvm::errs(), nullptr);
}
