#pragma once

#include "Scoping.hpp"
#include "Type.hpp"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <memory>

class ASTNode {
protected:
    void printIndent(int level) {
        for (int i = 0; i < 2 * level; i++)
            std::cout << " ";
    }

public:
    virtual ~ASTNode() = default;

    virtual void print() = 0;
    virtual void printTree(int level) = 0;
};

class ASTNode_Type : public ASTNode {
public:
    virtual std::shared_ptr<Type> getType(Environment &env) = 0;
};

class ASTNode_Type_Int : public ASTNode_Type {
public:
    std::shared_ptr<Type> getType(Environment &env) override {
        return std::make_shared<Type_Int>();
    }

    void print() override {
        std::cout << "int";
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_Type: int" << std::endl;
    }
};

class ASTNode_Type_Bool : public ASTNode_Type {
public:
    std::shared_ptr<Type> getType(Environment &env) override {
        return std::make_shared<Type_Bool>();
    }

    void print() override {
        std::cout << "bool";
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_Type: bool" << std::endl;
    }
};

class ASTNode_Type_Void : public ASTNode_Type {
public:
    std::shared_ptr<Type> getType(Environment &env) override {
        return std::make_shared<Type_Void>();
    }

    void print() override {
        std::cout << "void";
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_Type: void" << std::endl;
    }
};

class ASTNode_Type_ID : public ASTNode_Type {
private:
    std::string id;

public:
    ASTNode_Type_ID(const char *id_c)
        : id(id_c)
    {

    }

    std::shared_ptr<Type> getType(Environment &env) override {
        // get it from the first scope because that is where the classes are declared
        return env.getClassDescriptor(id)->getType();
    }

    void print() override {
        std::cout << id;
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_Type: " << id << std::endl;
    }
};

class ASTNode_Type_Int_Array : public ASTNode_Type {
public:
    std::shared_ptr<Type> getType(Environment &env) override {
        return std::make_shared<Type_Array>(std::make_shared<Type_Int>());
    }

    void print() override {
        std::cout << "int[]";
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_Type: int[]" << std::endl;
    }
};

class ASTNode_Type_Bool_Array : public ASTNode_Type {
public:
    std::shared_ptr<Type> getType(Environment &env) override {
        return std::make_shared<Type_Array>(std::make_shared<Type_Bool>());
    }

    void print() override {
        std::cout << "bool[]";
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_Type: bool[]" << std::endl;
    }
};

class ASTNode_Type_Void_Array : public ASTNode_Type {
public:
    std::shared_ptr<Type> getType(Environment &env) override {
        return std::make_shared<Type_Array>(std::make_shared<Type_Void>());
    }

    void print() override {
        std::cout << "void[]";
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_Type: void[]" << std::endl;
    }
};

class ASTNode_Type_ID_Array : public ASTNode_Type {
private:
    std::string id;

public:
    ASTNode_Type_ID_Array(const char *id_c)
        : id(id_c)
    {

    }

    std::shared_ptr<Type> getType(Environment &env) override {
        return env.getClassDescriptor(id)->getType();
    }

    void print() override {
        std::cout << id << "[]";
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_Type: " << id << "[]" << std::endl;
    }
};
class ASTNode_Expr : public ASTNode {
public:
    virtual std::shared_ptr<Type> getType(Environment &env, Descriptor_Class &class_desc, Descriptor_Method &method_desc) = 0;
};

class ASTNode_Expr_Times : public ASTNode_Expr {
private:
    std::unique_ptr<ASTNode_Expr> left;
    std::unique_ptr<ASTNode_Expr> right;

public:
    ASTNode_Expr_Times(ASTNode_Expr *left, ASTNode_Expr *right)
        : left(left), right(right)
    {

    }

    std::shared_ptr<Type> getType(Environment &env, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        std::shared_ptr<Type> left_type = left->getType(env, class_desc, method_desc);
        std::shared_ptr<Type> right_type = right->getType(env, class_desc, method_desc);

        if (!left_type->typeEqual(right_type) || left_type->getID() != TYPE_ID::INT) {
            std::cout << "[Error]: Cannot multiply " << left_type->getName() << " and " << right_type->getName() << std::endl;
            exit(1);
        }
        
        return left_type;
    }

    void print() override {
        left->print();
        std::cout << " * ";
        right->print();
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_Expr_Times" << std::endl;
        left->printTree(level + 1);
        right->printTree(level + 1);
    }
};

class ASTNode_Expr_Divide : public ASTNode_Expr {
private:
    std::unique_ptr<ASTNode_Expr> left;
    std::unique_ptr<ASTNode_Expr> right;

public:
    ASTNode_Expr_Divide(ASTNode_Expr *left, ASTNode_Expr *right)
        : left(left), right(right)
    {

    }

    std::shared_ptr<Type> getType(Environment &env, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        std::shared_ptr<Type> left_type = left->getType(env, class_desc, method_desc);
        std::shared_ptr<Type> right_type = right->getType(env, class_desc, method_desc);

        if (!left_type->typeEqual(right_type) || left_type->getID() != TYPE_ID::INT) {
            std::cout << "[Error]: Cannot divide " << left_type->getName() << " and " << right_type->getName() << std::endl;
            exit(1);
        }
        
        return left_type;
    }

    void print() override {
        left->print();
        std::cout << " / ";
        right->print();
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_Expr_Divide" << std::endl;
    }
};

class ASTNode_Expr_Plus : public ASTNode_Expr {
private:
    std::unique_ptr<ASTNode_Expr> left;
    std::unique_ptr<ASTNode_Expr> right;

public:
    ASTNode_Expr_Plus(ASTNode_Expr *left, ASTNode_Expr *right)
        : left(left), right(right)
    {

    }

    std::shared_ptr<Type> getType(Environment &env, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        std::shared_ptr<Type> left_type = left->getType(env, class_desc, method_desc);
        std::shared_ptr<Type> right_type = right->getType(env, class_desc, method_desc);

        if (!left_type->typeEqual(right_type) || left_type->getID() != TYPE_ID::INT) {
            std::cout << "[Error]: Cannot add " << left_type->getName() << " and " << right_type->getName() << std::endl;
            exit(1);
        }
        
        return left_type;
    }

    void print() override {
        left->print();
        std::cout << " + ";
        right->print();
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_Expr_Plus" << std::endl;
    }
};

class ASTNode_Expr_Minus : public ASTNode_Expr {
private:
    std::unique_ptr<ASTNode_Expr> left;
    std::unique_ptr<ASTNode_Expr> right;

public:
    ASTNode_Expr_Minus(ASTNode_Expr *left, ASTNode_Expr *right)
        : left(left), right(right)
    {

    }

    std::shared_ptr<Type> getType(Environment &env, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        std::shared_ptr<Type> left_type = left->getType(env, class_desc, method_desc);
        std::shared_ptr<Type> right_type = right->getType(env, class_desc, method_desc);

        if (!left_type->typeEqual(right_type) || left_type->getID() != TYPE_ID::INT) {
            std::cout << "[Error]: Cannot subtract " << left_type->getName() << " and " << right_type->getName() << std::endl;
            exit(1);
        }
        
        return left_type;
    }

    void print() override {
        left->print();
        std::cout << " - ";
        right->print();
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_Expr_Minus" << std::endl;
    }
};

class ASTNode_Expr_Parenthesis : public ASTNode_Expr {
private:
    std::unique_ptr<ASTNode_Expr> expr;

public:
    ASTNode_Expr_Parenthesis(ASTNode_Expr *expr)
        : expr(expr)
    {

    }

    std::shared_ptr<Type> getType(Environment &env, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override { 
        return expr->getType(env, class_desc, method_desc);
    }

    void print() override {
        std::cout << "( ";
        expr->print();
        std::cout << " )";
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_Expr_Parenthesis" << std::endl;
        expr->printTree(level + 1);
    }
};

class ASTNode_Expr_And : public ASTNode_Expr {
private:
    std::unique_ptr<ASTNode_Expr> left;
    std::unique_ptr<ASTNode_Expr> right;

public:
    ASTNode_Expr_And(ASTNode_Expr *left, ASTNode_Expr *right)
        : left(left), right(right)
    {

    }

    std::shared_ptr<Type> getType(Environment &env, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        std::shared_ptr<Type> left_type = left->getType(env, class_desc, method_desc);
        std::shared_ptr<Type> right_type = right->getType(env, class_desc, method_desc);

        if (!left_type->typeEqual(right_type) || left_type->getID() != TYPE_ID::BOOL) {
            std::cout << "[Error]: Cannot boolean AND " << left_type->getName() << " and " << right_type->getName() << std::endl;
            exit(1);
        }
        
        return left_type;
    }

    void print() override {
        left->print();
        std::cout << " && ";
        right->print();
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_Expr_And" << std::endl;

        left->printTree(level + 1);
        right->printTree(level + 1);
    }
};

class ASTNode_Expr_Or : public ASTNode_Expr {
private:
    std::unique_ptr<ASTNode_Expr> left;
    std::unique_ptr<ASTNode_Expr> right;

public:
    ASTNode_Expr_Or(ASTNode_Expr *left, ASTNode_Expr *right)
        : left(left), right(right)
    {

    }

    std::shared_ptr<Type> getType(Environment &env, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        std::shared_ptr<Type> left_type = left->getType(env, class_desc, method_desc);
        std::shared_ptr<Type> right_type = right->getType(env, class_desc, method_desc);

        if (!left_type->typeEqual(right_type) || left_type->getID() != TYPE_ID::BOOL) {
            std::cout << "[Error]: Cannot boolean OR " << left_type->getName() << " and " << right_type->getName() << std::endl;
            exit(1);
        }
        
        return left_type;
    }

    void print() override {
        left->print();
        std::cout << " || ";
        right->print();
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_Expr_Or" << std::endl;

        left->printTree(level + 1);
        right->printTree(level + 1);
    }
};

class ASTNode_Expr_Equivalent : public ASTNode_Expr {
private:
    std::unique_ptr<ASTNode_Expr> left;
    std::unique_ptr<ASTNode_Expr> right;

public:
    ASTNode_Expr_Equivalent(ASTNode_Expr *left, ASTNode_Expr *right)
        : left(left), right(right)
    {

    }

    std::shared_ptr<Type> getType(Environment &env, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        std::shared_ptr<Type> left_type = left->getType(env, class_desc, method_desc);
        std::shared_ptr<Type> right_type = right->getType(env, class_desc, method_desc);

        if (!left_type->typeEqual(right_type) || left_type->getID() == TYPE_ID::CLASS) {
            std::cout << "[Error]: Cannot check equality of " << left_type->getName() << " and " << right_type->getName() << std::endl;
            exit(1);
        }
        
        return left_type;
    }

    void print() override {
        left->print();
        std::cout << " == ";
        right->print();
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_Expr_Equivalent" << std::endl;

        left->printTree(level + 1);
        right->printTree(level + 1);
    }
};

class ASTNode_Expr_IsNotEqual : public ASTNode_Expr {
private:
    std::unique_ptr<ASTNode_Expr> left;
    std::unique_ptr<ASTNode_Expr> right;

public:
    ASTNode_Expr_IsNotEqual(ASTNode_Expr *left, ASTNode_Expr *right)
        : left(left), right(right)
    {

    }

    std::shared_ptr<Type> getType(Environment &env, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        std::shared_ptr<Type> left_type = left->getType(env, class_desc, method_desc);
        std::shared_ptr<Type> right_type = right->getType(env, class_desc, method_desc);

        if (!left_type->typeEqual(right_type) || left_type->getID() == TYPE_ID::CLASS) {
            std::cout << "[Error]: Cannot check negated equality of " << left_type->getName() << " and " << right_type->getName() << std::endl;
            exit(1);
        }
        
        return left_type;
    }

    void print() override {
        left->print();
        std::cout << " != ";
        right->print();
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_Expr_IsNotEqual" << std::endl;

        left->printTree(level + 1);
        right->printTree(level + 1);
    }
};

class ASTNode_Expr_LessThanOrEqual : public ASTNode_Expr {
private:
    std::unique_ptr<ASTNode_Expr> left;
    std::unique_ptr<ASTNode_Expr> right;

public:
    ASTNode_Expr_LessThanOrEqual(ASTNode_Expr *left, ASTNode_Expr *right)
        : left(left), right(right)
    {

    }

    std::shared_ptr<Type> getType(Environment &env, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        std::shared_ptr<Type> left_type = left->getType(env, class_desc, method_desc);
        std::shared_ptr<Type> right_type = right->getType(env, class_desc, method_desc);

        if (!left_type->typeEqual(right_type) || left_type->getID() == TYPE_ID::CLASS) {
            std::cout << "[Error]: Cannot less or equal of " << left_type->getName() << " and " << right_type->getName() << std::endl;
            exit(1);
        }
        
        return left_type;
    }

    void print() override {
        left->print();
        std::cout << " <= ";
        right->print();
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_Expr_LessThanOrEqual" << std::endl;

        left->printTree(level + 1);
        right->printTree(level + 1);
    }
};

class ASTNode_Expr_LessThan : public ASTNode_Expr {
private:
    std::unique_ptr<ASTNode_Expr> left;
    std::unique_ptr<ASTNode_Expr> right;

public:
    ASTNode_Expr_LessThan(ASTNode_Expr *left, ASTNode_Expr *right)
        : left(left), right(right)
    {

    }

    std::shared_ptr<Type> getType(Environment &env, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        std::shared_ptr<Type> left_type = left->getType(env, class_desc, method_desc);
        std::shared_ptr<Type> right_type = right->getType(env, class_desc, method_desc);

        if (!left_type->typeEqual(right_type) || left_type->getID() == TYPE_ID::CLASS) {
            std::cout << "[Error]: Cannot less than of " << left_type->getName() << " and " << right_type->getName() << std::endl;
            exit(1);
        }
        
        return left_type;
    }

    void print() override {
        left->print();
        std::cout << " < ";
        right->print();
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_Expr_LessThan" << std::endl;

        left->printTree(level + 1);
        right->printTree(level + 1);
    }
};

class ASTNode_Expr_GreaterThanOrEqual : public ASTNode_Expr {
private:
    std::unique_ptr<ASTNode_Expr> left;
    std::unique_ptr<ASTNode_Expr> right;

public:
    ASTNode_Expr_GreaterThanOrEqual(ASTNode_Expr *left, ASTNode_Expr *right)
        : left(left), right(right)
    {

    }

    std::shared_ptr<Type> getType(Environment &env, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        std::shared_ptr<Type> left_type = left->getType(env, class_desc, method_desc);
        std::shared_ptr<Type> right_type = right->getType(env, class_desc, method_desc);

        if (!left_type->typeEqual(right_type) || left_type->getID() == TYPE_ID::CLASS) {
            std::cout << "[Error]: Cannot greater than or equal of " << left_type->getName() << " and " << right_type->getName() << std::endl;
            exit(1);
        }
        
        return left_type;
    }

    void print() override {
        left->print();
        std::cout << " >= ";
        right->print();
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_Expr_GreaterThanOrEqual" << std::endl;

        left->printTree(level + 1);
        right->printTree(level + 1);
    }
};

class ASTNode_Expr_GreaterThan : public ASTNode_Expr {
private:
    std::unique_ptr<ASTNode_Expr> left;
    std::unique_ptr<ASTNode_Expr> right;

public:
    ASTNode_Expr_GreaterThan(ASTNode_Expr *left, ASTNode_Expr *right)
        : left(left), right(right)
    {

    }

    std::shared_ptr<Type> getType(Environment &env, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        std::shared_ptr<Type> left_type = left->getType(env, class_desc, method_desc);
        std::shared_ptr<Type> right_type = right->getType(env, class_desc, method_desc);

        if (!left_type->typeEqual(right_type) || left_type->getID() == TYPE_ID::CLASS) {
            std::cout << "[Error]: Cannot greater than of " << left_type->getName() << " and " << right_type->getName() << std::endl;
            exit(1);
        }
        
        return left_type;
    }

    void print() override {
        left->print();
        std::cout << " > ";
        right->print();
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_Expr_GreaterThan" << std::endl;

        left->printTree(level + 1);
        right->printTree(level + 1);
    }
};

class ASTNode_Expr_UnaryMinus : public ASTNode_Expr {
private:
    std::unique_ptr<ASTNode_Expr> expr;

public:
    ASTNode_Expr_UnaryMinus(ASTNode_Expr *expr)
        : expr(expr)
    {

    }

    std::shared_ptr<Type> getType(Environment &env, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        std::shared_ptr<Type> type = expr->getType(env, class_desc, method_desc);

        if (type->getID() != TYPE_ID::INT) {
            std::cout << "[Error]: Cannot negate " << type->getName() << std::endl;
            exit(1);
        }
        
        return type;
    }

    void print() override {
        std::cout << "-";
        expr->print();
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_Expr_UnaryMinus" << std::endl;

        expr->printTree(level + 1);
    }
};

class ASTNode_Expr_BooleanNegate : public ASTNode_Expr {
private:
    std::unique_ptr<ASTNode_Expr> expr;

public:
    ASTNode_Expr_BooleanNegate(ASTNode_Expr *expr)
        : expr(expr)
    {

    }

    std::shared_ptr<Type> getType(Environment &env, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        std::shared_ptr<Type> type = expr->getType(env, class_desc, method_desc);

        if (type->getID() != TYPE_ID::INT) {
            std::cout << "[Error]: Cannot logically negate " << type->getName() << std::endl;
            exit(1);
        }
        
        return type;
    }

    void print() override {
        std::cout << "!";
        expr->print();
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_Expr_BooleanNegate" << std::endl;

        expr->printTree(level + 1);
    }
};

class ASTNode_Expr_Integer : public ASTNode_Expr {
private:
    int64_t integer;

public:
    ASTNode_Expr_Integer(int64_t integer)
        : integer(integer)
    {

    }

    std::shared_ptr<Type> getType(Environment &env, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override { return std::make_shared<Type_Int>(); }

    void print() override {
        std::cout << integer;
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_Expr_Integer: " << integer << std::endl;
    }
};

class ASTNode_Expr_Boolean : public ASTNode_Expr {
private:
    bool boolean;

public:
    ASTNode_Expr_Boolean(bool boolean)
        : boolean(boolean)
    {

    }

    std::shared_ptr<Type> getType(Environment &env, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override { return std::make_shared<Type_Bool>(); }

    void print() override {
        std::cout << (boolean ? "true" : "false");
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_Expr_Boolean: " << boolean << std::endl;
    }
};

class ASTNode_Actuals : public ASTNode {
private:
    std::vector<std::unique_ptr<ASTNode_Expr>> expressions;

public:
    ASTNode_Actuals() {

    }

    void AddExpression(ASTNode_Expr *expr) {
        expressions.insert(expressions.begin(), std::unique_ptr<ASTNode_Expr>(expr));
    }

    void print() override {
        for (size_t i = 0; i < expressions.size(); i++) {
            if (i == 0) {
                expressions[0]->print();
            } else {
                std::cout << ", ";
                expressions[i]->print();
            }
        }
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_Actuals" << std::endl;

        for (auto& expr : expressions)
            expr->printTree(level + 1);
    }
};

class ASTNode_Expr_New_Obj : public ASTNode_Expr {
private:
    std::unique_ptr<ASTNode_Actuals> actuals;
    std::string type;

public:
    ASTNode_Expr_New_Obj(ASTNode_Actuals *actuals, const char *type_c)
        : actuals(actuals), type(type_c)
    {

    }

    std::shared_ptr<Type> getType(Environment &env, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        return env.getClassDescriptor(type)->getType();
    }

    void print() override {
        std::cout << "new " << type << "( ";
        actuals->print();
        std::cout << " )";
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_Expr_New_Obj: " << type << std::endl;
        actuals->printTree(level + 1);
    }
};

class ASTNode_Expr_New_Array : public ASTNode_Expr {
private:
    std::unique_ptr<ASTNode_Type> type;
    std::unique_ptr<ASTNode_Expr> expr;

public:
    ASTNode_Expr_New_Array(ASTNode_Type *type, ASTNode_Expr *expr)
        : type(type), expr(expr)
    {

    }

    std::shared_ptr<Type> getType(Environment &env, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        auto arr_type = std::make_shared<Type_Array>(type->getType(env));
        return arr_type;
    }

    void print() override {
        std::cout << "new int [ ";
        expr->print();
        std::cout << " ]";
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_Expr_New_Array" << std::endl;
        type->printTree(level + 1);
        expr->printTree(level + 1);
    }
};

class ASTNode_Statement : public ASTNode {
public:
    virtual void pass_3(Environment &env, Descriptor_Class &class_desc, Descriptor_Method &method_desc) = 0;
};

class ASTNode_Statement_ExprOnly : public ASTNode_Statement {
private:
    std::unique_ptr<ASTNode_Expr> expr;

public:
    ASTNode_Statement_ExprOnly(ASTNode_Expr *expr) 
        : expr(expr)
    {

    }

    void pass_3(Environment &env, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        expr->getType(env, class_desc, method_desc);
    }

    void print() override {
        expr->print();
        std::cout << ";" << std::endl;
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_Statement_ExprOnly" << std::endl;
        expr->printTree(level + 1);
    }
};

class ASTNode_Statement_VariableDeclaration : public ASTNode_Statement {
private:
    std::unique_ptr<ASTNode_Type> type;
    std::string name;

public:
    ASTNode_Statement_VariableDeclaration(ASTNode_Type *type, const char* name_c)
        : type(type), name(name_c)
    {

    }

    void pass_3(Environment &env, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        env.getTopScope()->setVariableDescriptor(name, std::make_shared<Descriptor_Variable>(type->getType(env)));
    }

    void print() override {
        type->print();
        std::cout << " " << name << ";" << std::endl;
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_Statement_VariableDeclaration: " << name << std::endl;
        type->printTree(level + 1);
    }
};

class ASTNode_Statement_Empty : public ASTNode_Statement {
public:
    ASTNode_Statement_Empty() {

    }

    void pass_3(Environment &env, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {

    }

    void print() override {
        std::cout << ";" << std::endl;
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_Statement_Empty" << std::endl;
    }
};

class ASTNode_Statement_Return : public ASTNode_Statement {
private:
    std::unique_ptr<ASTNode_Expr> expr;

public:
    ASTNode_Statement_Return(ASTNode_Expr *expr) 
        : expr(expr)
    {

    }

    void pass_3(Environment &env, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        auto expr_type = expr->getType(env, class_desc, method_desc);
        method_desc.setHasReturnStmt(true);

        if (!expr_type->typeEqual(method_desc.getReturnType())) {
            std::cout << "[Error]: Return type " << expr_type->getName() << " does not match the expected return type " << method_desc.getReturnType()->getName() << " in function " << method_desc.getName() << std::endl;
            exit(1);
        }
    }

    void print() override {
        std::cout << "return ";
        expr->print();
        std::cout << ";" << std::endl;
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_Statement_Return" << std::endl;
        expr->printTree(level + 1);
    }
};

class ASTNode_Statement_Body : public ASTNode_Statement {
private:
    std::vector<std::unique_ptr<ASTNode_Statement>> nodes;

public:
    ASTNode_Statement_Body() {

    }

    void pass_3(Environment &env, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        for (auto& statement : nodes)
            statement->pass_3(env, class_desc, method_desc);
    }

    void AddStatement(ASTNode_Statement *statement) {
        // bottom up parsing...
        nodes.insert(nodes.begin(), std::unique_ptr<ASTNode_Statement>(statement));
    }

    void print() override {
        std::cout << "{" << std::endl;
        for (auto &statement : nodes)
            statement->print();
        std::cout << "}" << std::endl;
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_Statement_Body" << std::endl;
        for (auto& node : nodes)
            node->printTree(level + 1);
    }
};

class ASTNode_Statement_While : public ASTNode_Statement {
private:
    std::unique_ptr<ASTNode_Expr> condition_expr;
    std::unique_ptr<ASTNode_Statement> statement;

public:
    ASTNode_Statement_While(ASTNode_Expr *condition_expr, ASTNode_Statement *statement)
        : condition_expr(condition_expr), statement(statement)
    {

    }

    void pass_3(Environment &env, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        auto condition_type = condition_expr->getType(env, class_desc, method_desc);
        if (condition_type->getID() != TYPE_ID::BOOL) {
            std::cout << "[Error]: Condition expression of while expects a boolean. Got " << condition_type->getName() << std::endl; 
            exit(1);
        }

        statement->pass_3(env, class_desc, method_desc);
    }

    void print() override {
        std::cout << "while ( ";
        condition_expr->print();
        std::cout << " )" << std::endl;
        statement->print();
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_Statement_While" << std::endl;
        condition_expr->printTree(level + 1);
        statement->printTree(level + 1);
    }
};

class ASTNode_Statement_If : public ASTNode_Statement {
private:
    std::unique_ptr<ASTNode_Expr> condition_expr;
    std::unique_ptr<ASTNode_Statement> statement;

public:
    ASTNode_Statement_If(ASTNode_Expr *condition_expr, ASTNode_Statement *statement) 
        : condition_expr(condition_expr), statement(statement)
    {

    }

    void pass_3(Environment &env, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        auto cond_type = condition_expr->getType(env, class_desc, method_desc);
        if (cond_type->getID() != TYPE_ID::BOOL) {
            std::cout << "[Error]: if statement conditional expression must be of type boolean. Attempted type: " << cond_type->getName() << std::endl;
            exit(1);
        }

        statement->pass_3(env, class_desc, method_desc);
    }

    void print() override {
        std::cout << "if ( ";
        condition_expr->print();
        std::cout << ")" << std::endl;
        statement->print();
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_Statement_If" << std::endl;
        condition_expr->printTree(level + 1);
        statement->printTree(level + 1);
    }
};

class ASTNode_Statement_IfElse : public ASTNode_Statement {
private:
    std::unique_ptr<ASTNode_Expr> condition_expr;
    std::unique_ptr<ASTNode_Statement> statement_true;
    std::unique_ptr<ASTNode_Statement> statement_false;

public:
    ASTNode_Statement_IfElse(ASTNode_Expr *condition_expr, ASTNode_Statement *statement_true, ASTNode_Statement *statement_false) 
        : condition_expr(condition_expr), statement_true(statement_true), statement_false(statement_false)
    {

    }

    void pass_3(Environment &env, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        auto condition_type = condition_expr->getType(env, class_desc, method_desc);
        if (condition_type->getID() != TYPE_ID::BOOL) {
            std::cout << "[Error]: IfElse expects a boolean conditional type. Got " << condition_type->getName() << std::endl;
            exit(1);
        }

        statement_true->pass_3(env, class_desc, method_desc);
        statement_false->pass_3(env, class_desc, method_desc);
    }

    void print() override {
        std::cout << "if ( ";
        condition_expr->print();
        std::cout << ")" << std::endl;
        statement_true->print();
        std::cout << "else" << std::endl;
        statement_false->print();
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_Statement_IfElse" << std::endl;
        condition_expr->printTree(level + 1);
        statement_true->printTree(level + 1);
        statement_false->printTree(level + 1);
    }
};

class ASTNode_LValue : public ASTNode_Expr {

};

class ASTNode_LValue_ID : public ASTNode_LValue {
private:
    std::string id;

public:
    ASTNode_LValue_ID(const char *id_c)
        : id(id_c)
    {

    }

    std::shared_ptr<Type> getType(Environment &env, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        std::cout << "ID: " << id << std::endl;
        return env.getVariableDescriptor(id)->getType();
    }

    void print() override {
        std::cout << id;
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_LValue_ID: " << id << std::endl;
    }
};

class ASTNode_LValue_MethodCall : public ASTNode_LValue {
private:
    std::unique_ptr<ASTNode_Actuals> actuals;
    std::string id;

public:
    ASTNode_LValue_MethodCall(ASTNode_Actuals *actuals, const char *id_c)
        : actuals(actuals), id(id_c)
    {

    }

    std::shared_ptr<Type> getType(Environment &env, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        // this method name should be in scope
        return env.getMethodDescriptor(id)->getReturnType();
    }

    void print() override {
        std::cout << id << "(";
        actuals->print();
        std::cout << ")";
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_LValue_MethodCall: " << id << std::endl;
        actuals->printTree(level + 1);
    }
};

class ASTNode_LValue_Obj_Access : public ASTNode_LValue {
private:
    std::unique_ptr<ASTNode_LValue> obj_lvalue;
    std::string id;

public:
    ASTNode_LValue_Obj_Access(ASTNode_LValue *obj_lvalue, const char *id_c)
        : obj_lvalue(obj_lvalue), id(id_c)
    {

    }

    std::shared_ptr<Type> getType(Environment &env, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        std::shared_ptr<Type> callee_type = obj_lvalue->getType(env, class_desc, method_desc);
        Scope::MaybeVariableDescriptor desc = callee_type->getScope()->getVariableDescriptor(id);
        if (!desc.has_value()) {
            std::cout << "[Error]: Obj of type " << callee_type->getName() << " does not have a member named " << id << std::endl;
            exit(1);
        }

        return desc.value()->getType();
    }

    void print() override {
        obj_lvalue->print();
        std::cout << "." << id;
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_LValue_Obj_Access: " << id << std::endl;
        obj_lvalue->printTree(level + 1);
    }    
};

class ASTNode_LValue_Obj_MethodCall : public ASTNode_LValue {
private:
    std::unique_ptr<ASTNode_LValue> obj_lvalue;
    std::string id;
    std::unique_ptr<ASTNode_Actuals> actuals;

public:
    ASTNode_LValue_Obj_MethodCall(ASTNode_LValue *obj_lvalue, const char *id_c, ASTNode_Actuals *actuals)
        : obj_lvalue(obj_lvalue), id(id_c), actuals(actuals)
    {

    }

    std::shared_ptr<Type> getType(Environment &env, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        std::shared_ptr<Type> callee_type = obj_lvalue->getType(env, class_desc, method_desc);
        Scope::MaybeMethodDescriptor desc = callee_type->getScope()->getMethodDescriptor(id);
        if (!desc.has_value()) {
            std::cout << "[Error]: Obj of type " << callee_type->getName() << " does not have method named " << id << std::endl;
            exit(1);
        }

        return desc.value()->getReturnType();
    }

    void print() override {
        obj_lvalue->print();
        std::cout << "." << id;
        std::cout << "(";
        actuals->print();
        std::cout << ")";
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_LValue_Obj_MethodCall: " << id << std::endl;
        obj_lvalue->printTree(level + 1);
        actuals->printTree(level + 1);
    }
};

class ASTNode_LValue_Array : public ASTNode_LValue {
private:
    std::unique_ptr<ASTNode_LValue> lvalue;
    std::unique_ptr<ASTNode_Expr> expr;

public:
    ASTNode_LValue_Array(ASTNode_LValue *lvalue, ASTNode_Expr *expr)
        : lvalue(lvalue), expr(expr)
    {

    }

    std::shared_ptr<Type> getType(Environment &env, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        std::shared_ptr<Type> callee_type = lvalue->getType(env, class_desc, method_desc);
        std::shared_ptr<Type> expr_type = expr->getType(env, class_desc, method_desc);

        if (callee_type->getID() != TYPE_ID::ARRAY) {
            std::cout << "[Error]: Type " << callee_type->getName() << " being accessed like an array, but it is not an array" << std::endl; 
            exit(1);
        }

        return callee_type->getCompositeType();
    }

    void print() override {
        lvalue->print();
        std::cout << "[";
        expr->print();
        std::cout << "]";
    }

    void printTree(int level) override {
        printIndent(level + 1);
        std::cout << "ASTNode_LValue_Array" << std::endl;
        lvalue->printTree(level + 1);
        expr->printTree(level + 1);
    }
};

class ASTNode_LValue_This : public ASTNode_LValue { 
public:
    std::shared_ptr<Type> getType(Environment &env, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        return class_desc.getType();
    }

    void print() override {
        std::cout << "this";
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_LValue_This" << std::endl;
    }
};

class ASTNode_Statement_Assignment : public ASTNode_Statement {
private:
    std::unique_ptr<ASTNode_LValue> lvalue;
    std::unique_ptr<ASTNode_Expr> expr;

public:
    ASTNode_Statement_Assignment(ASTNode_LValue *lvalue, ASTNode_Expr *expr)
        : lvalue(lvalue), expr(expr)
    {

    }

    void pass_3(Environment &env, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        auto lvalue_type = lvalue->getType(env, class_desc, method_desc);
        auto expr_type = expr->getType(env, class_desc, method_desc);

        if (!lvalue_type->typeEqual(expr_type)) {
            std::cout << "[Error]: Cannot assign to a type " << lvalue_type->getName() << " with type " << expr_type->getName() << std::endl;
            exit(1);
        }
    }

    void print() override {
        lvalue->print();
        std::cout << " = ";
        expr->print();
        std::cout << ";" << std::endl;
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_Statement_Assignment" << std::endl;
        lvalue->printTree(level + 1);
        expr->printTree(level + 1);
    }
};

class ASTNode_Formal : public ASTNode {
private:
    std::unique_ptr<ASTNode_Type> type;
    std::string id;

public:
    ASTNode_Formal(ASTNode_Type *type, const char *id_c) 
        : type(type), id(id_c)
    {

    }

    void pass_2(Environment& env, std::shared_ptr<Descriptor_Method> method_descriptor) {
        env.getTopScope()->setVariableDescriptor(id, std::make_shared<Descriptor_Variable>(type->getType(env)));
        method_descriptor->addArgumentType(type->getType(env));
    }

    void print() override {
        type->print();
        std::cout << " " << id;
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_Formal: " << id << std::endl;
        type->printTree(level + 1);
    }
};

class ASTNode_Formal_List : public ASTNode {
private:
    std::vector<std::unique_ptr<ASTNode_Formal>> formals;

public:
    void AddFormal(ASTNode_Formal *formal) {
        formals.insert(formals.begin(), std::unique_ptr<ASTNode_Formal>(formal));
    }

    void pass_2(Environment& env, std::shared_ptr<Descriptor_Method> method_descriptor) {
        for (auto& formal : formals)
            formal->pass_2(env, method_descriptor);
    }

    void print() override {
        for (int i = 0; i < formals.size(); i++) {
            if (i != 0)
                std::cout << ", ";
            formals[i]->print();
        }
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_Formal_List" << std::endl;
        for (auto &f : formals)
            f->printTree(level + 1);
    }
};

class ASTNode_MemberDeclaration : public ASTNode {
public:
    virtual void pass_2(Environment &env, Descriptor_Class &class_desc) = 0;
    virtual void pass_3(Environment &env, Descriptor_Class &class_desc) = 0;
};

class ASTNode_MemberDeclaration_Variable : public ASTNode_MemberDeclaration {
private:
    std::unique_ptr<ASTNode_Type> type;
    std::string id;

public:
    ASTNode_MemberDeclaration_Variable(ASTNode_Type *type, const char *id_c)
        : type(type), id(id_c)
    {

    }

    void pass_2(Environment &env, Descriptor_Class &class_desc) override {
        auto desc = std::make_shared<Descriptor_Variable>(type->getType(env));
        env.getTopScope()->setVariableDescriptor(id, desc);
        class_desc.addField(desc);
    }

    void pass_3(Environment &env, Descriptor_Class &class_desc) override {

    }

    void print() override {
        type->print();
        std::cout << id << ";" << std::endl;
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_MemberDeclaration_Variable: " << id << std::endl;
        type->printTree(level + 1);
    }
};

class ASTNode_MemberDeclaration_Function : public ASTNode_MemberDeclaration {
private:
    std::unique_ptr<ASTNode_Type> type;
    std::unique_ptr<ASTNode_Formal_List> formals;
    std::string id;
    std::unique_ptr<ASTNode_Statement_Body> body;

    std::shared_ptr<Scope> argument_scope;
    std::shared_ptr<Scope> body_scope;

    std::shared_ptr<Descriptor_Method> desc;

public:
    ASTNode_MemberDeclaration_Function(ASTNode_Type *type, ASTNode_Formal_List *formals, const char *id_c, ASTNode_Statement_Body *body)
        : type(type), formals(formals), id(id_c), body(body), argument_scope(std::make_shared<Scope>()), body_scope(std::make_shared<Scope>()), desc(nullptr)
    {

    }

    void pass_2(Environment &env, Descriptor_Class &class_desc) override {
        desc = std::make_shared<Descriptor_Method>(id, type->getType(env));
        env.getTopScope()->setMethodDescriptor(id, desc);
        class_desc.addMethod(desc);

        env.pushScope(argument_scope);
            formals->pass_2(env, desc);
        env.popScope();
    }

    void pass_3(Environment &env, Descriptor_Class &class_desc) override {
        env.pushScope(argument_scope);
        env.pushScope(body_scope);
            body->pass_3(env, class_desc, *desc);
        env.popScope();
        env.popScope();

        if (!desc->hasReturnStmt() && desc->getReturnType()->getID() != TYPE_ID::VOID) {
            std::cout << "[Error]: Method " << desc->getName() << " does not have a return statement!" << std::endl;
            exit(1);
        }
    }

    void print() override {
        type->print();
        std::cout << " " << id << "( ";
        formals->print();
        std::cout << " )" << std::endl;

        body->print();
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_MemberDeclaration_Function: " << id << std::endl;
        type->printTree(level + 1);
        formals->printTree(level + 1);
        body->printTree(level + 1);
    }
};

class ASTNode_MemberDeclaration_Constructor : public ASTNode_MemberDeclaration {
private:
    std::unique_ptr<ASTNode_Formal_List> formals;
    std::string id;
    std::unique_ptr<ASTNode_Statement_Body> body;

    std::shared_ptr<Scope> argument_scope;
    std::shared_ptr<Scope> body_scope;

    std::shared_ptr<Descriptor_Constructor> desc;

public:
    ASTNode_MemberDeclaration_Constructor(ASTNode_Formal_List *formals, const char *id_c, ASTNode_Statement_Body *body)
        : formals(formals), id(id_c), body(body), argument_scope(std::make_shared<Scope>()), body_scope(std::make_shared<Scope>()), desc(nullptr)
    {

    }

    void pass_2(Environment &env, Descriptor_Class &class_desc) override {
        this->desc = std::make_shared<Descriptor_Constructor>(id);
        env.getTopScope()->setMethodDescriptor(id, desc);
        class_desc.setConstructor(desc);

        env.pushScope(argument_scope);
            formals->pass_2(env, desc);
        env.popScope();
    }

    void pass_3(Environment &env, Descriptor_Class &class_desc) override {
        env.pushScope(argument_scope);
        env.pushScope(body_scope);
            body->pass_3(env, class_desc, *desc);
        env.popScope();
        env.popScope();
    }

    void print() override {
        std::cout << id << "( ";
        formals->print();
        std::cout << " )" << std::endl;

        std::cout << "{" << std::endl;
        body->print();
        std::cout << "}" << std::endl;
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_MemberDeclaration_Constructor: " << id << std::endl;
        formals->printTree(level + 1);
        body->printTree(level + 1);
    }
};

class ASTNode_MemberDeclaration_List : public ASTNode {
private:
    std::vector<std::unique_ptr<ASTNode_MemberDeclaration>> declarations;

public:
    ASTNode_MemberDeclaration_List() {

    }

    void AddDeclaration(ASTNode_MemberDeclaration *decl) {
        declarations.insert(declarations.begin(), std::unique_ptr<ASTNode_MemberDeclaration>(decl));
    }

    void pass_2(Environment &env, Descriptor_Class &class_desc) {
        for (auto& decl : declarations)
            decl->pass_2(env, class_desc);
    }

    void pass_3(Environment &env, Descriptor_Class &class_desc) {
        for (auto& decl : declarations)
            decl->pass_3(env, class_desc);
    }

    void print() override {
        for (auto& decl : declarations)
            decl->print();
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_MemberDeclaration_List" << std::endl;
        for (auto& decl : declarations)
            decl->printTree(level);
    }
};

class ASTNode_Class : public ASTNode {
protected:
    std::string name;
    std::unique_ptr<ASTNode_MemberDeclaration_List> declarations;
    std::shared_ptr<Scope> scope;

    std::shared_ptr<Descriptor_Class> desc;

public:
    ASTNode_Class(const char *name_c, ASTNode_MemberDeclaration_List *declarations)
        : name(name_c), declarations(declarations), scope(std::make_shared<Scope>()), desc(std::make_shared<Descriptor_Class>(name))
    {

    }

    virtual void pass_0(Environment &env) {
        env.setClassDescriptor(name, desc);
        this->desc->getType()->setScope(scope);

        std::cout << *desc << std::endl << std::endl;
    }

    virtual void pass_1(Environment &env) {

    }

    virtual void pass_2(Environment & env) {
        this->desc->getType()->pushScope(env);
            declarations->pass_2(env, *desc);
            //std::cout << *scope << std::endl;
            std::cout << *desc << std::endl << std::endl;
        this->desc->getType()->popScope(env);
    }

    virtual void pass_3(Environment &env) {
        if (!desc->hasConstructor()) {
            std::cout << "Class " << name << " does not have a constructor!" << std::endl;
            exit(1);
        }

        this->desc->getType()->pushScope(env);
            declarations->pass_3(env, *desc);
        this->desc->getType()->popScope(env);
    }

    void print() override {
        std::cout << "class " << name << std::endl;
        std::cout << "{" << std::endl;

        declarations->print();

        std::cout << "};" << std::endl;
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_Class: " << name << std::endl;
        declarations->printTree(level + 1);
    }
};

class ASTNode_Class_Child : public ASTNode_Class {
protected:
    std::string parent_name;

public:
    ASTNode_Class_Child(const char *name_c, const char *parent_name_c, ASTNode_MemberDeclaration_List *declarations)
        : ASTNode_Class(name_c, declarations), parent_name(parent_name_c)
    {

    }

    void pass_1(Environment &env) override {
        auto parent_desc = env.getClassDescriptor(parent_name);

        desc->getType()->setParentClassType(parent_desc->getType());
        std::cout << *desc << std::endl << std::endl;
    }

    void print() override {
        std::cout << "class " << name << " extends " << parent_name << std::endl;
        std::cout << "{" << std::endl;

        declarations->print();

        std::cout << "};" << std::endl;
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_Class_Child: " << name << " extends " << parent_name << std::endl;
        declarations->printTree(level + 1);
    }
};

class ASTNode_Class_List : public ASTNode {
private:
    std::vector<std::unique_ptr<ASTNode_Class>> classes;
    std::shared_ptr<Scope> scope;

public:
    ASTNode_Class_List() : scope(std::make_shared<Scope>()) {

    }

    void AddClass(ASTNode_Class *clazz) {
        classes.insert(classes.begin(), std::unique_ptr<ASTNode_Class>(clazz));
    }

    void pass_0(Environment &env) {
        env.pushScope(scope);
            for (auto& clazz : classes)
                clazz->pass_0(env);
        env.popScope();
    }

    void pass_1(Environment &env) {
        env.pushScope(scope);
            for (auto& clazz : classes)
                clazz->pass_1(env);
        env.popScope();

        //std::cout << *scope << std::endl;
    }

    void pass_2(Environment & env) {
        env.pushScope(scope);
            for (auto& clazz : classes)
                clazz->pass_2(env);
        env.popScope();

        //std::cout << *scope << std::endl;
    }

    void pass_3(Environment & env) {
        env.pushScope(scope);
            if (env.hasClassDescriptor("Main")) {
                for (auto& clazz : classes)
                    clazz->pass_3(env);
            } else {
                // Does not have main class
                std::cout << "[Error]: Code does not contain a Main class!" << std::endl;
                exit(1);
            }

        env.popScope();
    }

    void print() override {
        for (auto& c : classes)
            c->print();
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_Class_List" << std::endl;
        for (auto& cl : classes)
            cl ->printTree(level + 1);
    }
};

class AST {
public:
    ASTNode_Class_List root;

    void pass_0(Environment &env) {
        root.pass_0(env);
    }

    void pass_1(Environment &env) {
        root.pass_1(env);
    }

    void pass_2(Environment &env) {
        root.pass_2(env);
    }

    void pass_3(Environment &env) { 
        root.pass_3(env);
    }
};
