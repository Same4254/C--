#pragma once

#include <cstdlib>
#include <iostream>
#include <llvm-10/llvm/IR/DataLayout.h>
#include <vector>
#include <memory>

#include "Scoping.hpp"
#include "Type.hpp"

#include "GeneratedCode.hpp"

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
    virtual llvm::Value* genCode(Environment &env, GeneratedCode &code, Descriptor_Class &class_desc, Descriptor_Method &method_desc) = 0;
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

    llvm::Value* genCode(Environment &env, GeneratedCode &code, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        llvm::Value* left_code = left->genCode(env, code, class_desc, method_desc);
        llvm::Value* right_code = right->genCode(env, code, class_desc, method_desc);

        return code.getBuilder().CreateMul(left_code, right_code);
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

    llvm::Value* genCode(Environment &env, GeneratedCode &code, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        llvm::Value* left_code = left->genCode(env, code, class_desc, method_desc);
        llvm::Value* right_code = right->genCode(env, code, class_desc, method_desc);

        return code.getBuilder().CreateSDiv(left_code, right_code);
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

    llvm::Value* genCode(Environment &env, GeneratedCode &code, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        llvm::Value* left_code = left->genCode(env, code, class_desc, method_desc);
        llvm::Value* right_code = right->genCode(env, code, class_desc, method_desc);

        // temps are on the stack, so if LHS or RHS is an id, we need to get the value
        if (left_code->getType()->isPointerTy())
            left_code = code.getBuilder().CreateLoad(left_code->getType()->getPointerElementType(), left_code);

        if (right_code->getType()->isPointerTy())
            right_code = code.getBuilder().CreateLoad(right_code->getType()->getPointerElementType(), right_code);

        return code.getBuilder().CreateAdd(left_code, right_code);
    }

    void print() override {
        left->print();
        std::cout << " + ";
        right->print();
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_Expr_Plus" << std::endl;
        left->printTree(level + 1);
        right->printTree(level + 1);
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

    llvm::Value* genCode(Environment &env, GeneratedCode &code, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        llvm::Value* left_code = left->genCode(env, code, class_desc, method_desc);
        llvm::Value* right_code = right->genCode(env, code, class_desc, method_desc);

        // temps are on the stack, so if LHS or RHS is an id, we need to get the value
        if (left_code->getType()->isPointerTy())
            left_code = code.getBuilder().CreateLoad(left_code->getType()->getPointerElementType(), left_code);

        if (right_code->getType()->isPointerTy())
            right_code = code.getBuilder().CreateLoad(right_code->getType()->getPointerElementType(), right_code);

        return code.getBuilder().CreateSub(left_code, right_code);
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

    llvm::Value* genCode(Environment &env, GeneratedCode &code, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        return expr->genCode(env, code, class_desc, method_desc);
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

    llvm::Value* genCode(Environment &env, GeneratedCode &code, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        llvm::Value* left_code = left->genCode(env, code, class_desc, method_desc);
        llvm::Value* right_code = right->genCode(env, code, class_desc, method_desc);

        // temps are on the stack, so if LHS or RHS is an id, we need to get the value
        if (left_code->getType()->isPointerTy())
            left_code = code.getBuilder().CreateLoad(left_code->getType()->getPointerElementType(), left_code);

        if (right_code->getType()->isPointerTy())
            right_code = code.getBuilder().CreateLoad(right_code->getType()->getPointerElementType(), right_code);

        return code.getBuilder().CreateAnd(left_code, right_code);
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

    llvm::Value* genCode(Environment &env, GeneratedCode &code, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        llvm::Value* left_code = left->genCode(env, code, class_desc, method_desc);
        llvm::Value* right_code = right->genCode(env, code, class_desc, method_desc);

        // temps are on the stack, so if LHS or RHS is an id, we need to get the value
        if (left_code->getType()->isPointerTy())
            left_code = code.getBuilder().CreateLoad(left_code->getType()->getPointerElementType(), left_code);

        if (right_code->getType()->isPointerTy())
            right_code = code.getBuilder().CreateLoad(right_code->getType()->getPointerElementType(), right_code);

        return code.getBuilder().CreateOr(left_code, right_code);
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

    llvm::Value* genCode(Environment &env, GeneratedCode &code, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        llvm::Value* left_code = left->genCode(env, code, class_desc, method_desc);
        llvm::Value* right_code = right->genCode(env, code, class_desc, method_desc);

        // temps are on the stack, so if LHS or RHS is an id, we need to get the value
        if (left_code->getType()->isPointerTy())
            left_code = code.getBuilder().CreateLoad(left_code->getType()->getPointerElementType(), left_code);

        if (right_code->getType()->isPointerTy())
            right_code = code.getBuilder().CreateLoad(right_code->getType()->getPointerElementType(), right_code);

        return code.getBuilder().CreateICmpEQ(left_code, right_code);
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

    llvm::Value* genCode(Environment &env, GeneratedCode &code, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        llvm::Value* left_code = left->genCode(env, code, class_desc, method_desc);
        llvm::Value* right_code = right->genCode(env, code, class_desc, method_desc);

        // temps are on the stack, so if LHS or RHS is an id, we need to get the value
        if (left_code->getType()->isPointerTy())
            left_code = code.getBuilder().CreateLoad(left_code->getType()->getPointerElementType(), left_code);

        if (right_code->getType()->isPointerTy())
            right_code = code.getBuilder().CreateLoad(right_code->getType()->getPointerElementType(), right_code);

        return code.getBuilder().CreateNot(code.getBuilder().CreateICmpEQ(left_code, right_code), "t");
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

        if (!left_type->typeEqual(right_type) || left_type->getID() != TYPE_ID::INT) {
            std::cout << "[Error]: Cannot less or equal of " << left_type->getName() << " and " << right_type->getName() << std::endl;
            exit(1);
        }
        
        return std::make_shared<Type_Bool>();
    }

    llvm::Value* genCode(Environment &env, GeneratedCode &code, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        llvm::Value* left_code = left->genCode(env, code, class_desc, method_desc);
        llvm::Value* right_code = right->genCode(env, code, class_desc, method_desc);

        // temps are on the stack, so if LHS or RHS is an id, we need to get the value
        if (left_code->getType()->isPointerTy())
            left_code = code.getBuilder().CreateLoad(left_code->getType()->getPointerElementType(), left_code);

        if (right_code->getType()->isPointerTy())
            right_code = code.getBuilder().CreateLoad(right_code->getType()->getPointerElementType(), right_code);

        return code.getBuilder().CreateICmpSLE(left_code, right_code);
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

        if (!left_type->typeEqual(right_type) || left_type->getID() != TYPE_ID::INT) {
            std::cout << "[Error]: Cannot less than of " << left_type->getName() << " and " << right_type->getName() << std::endl;
            exit(1);
        }
        
        return std::make_shared<Type_Bool>();
    }

    llvm::Value* genCode(Environment &env, GeneratedCode &code, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        llvm::Value* left_code = left->genCode(env, code, class_desc, method_desc);
        llvm::Value* right_code = right->genCode(env, code, class_desc, method_desc);

        // temps are on the stack, so if LHS or RHS is an id, we need to get the value
        if (left_code->getType()->isPointerTy())
            left_code = code.getBuilder().CreateLoad(left_code->getType()->getPointerElementType(), left_code);

        if (right_code->getType()->isPointerTy())
            right_code = code.getBuilder().CreateLoad(right_code->getType()->getPointerElementType(), right_code);

        return code.getBuilder().CreateICmpSLT(left_code, right_code);
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

        if (!left_type->typeEqual(right_type) || left_type->getID() != TYPE_ID::INT) {
            std::cout << "[Error]: Cannot greater than or equal of " << left_type->getName() << " and " << right_type->getName() << std::endl;
            exit(1);
        }
        
        return std::make_shared<Type_Bool>();
    }

    llvm::Value* genCode(Environment &env, GeneratedCode &code, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        llvm::Value* left_code = left->genCode(env, code, class_desc, method_desc);
        llvm::Value* right_code = right->genCode(env, code, class_desc, method_desc);

        // temps are on the stack, so if LHS or RHS is an id, we need to get the value
        if (left_code->getType()->isPointerTy())
            left_code = code.getBuilder().CreateLoad(left_code->getType()->getPointerElementType(), left_code);

        if (right_code->getType()->isPointerTy())
            right_code = code.getBuilder().CreateLoad(right_code->getType()->getPointerElementType(), right_code);

        return code.getBuilder().CreateICmpSGE(left_code, right_code);
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

        if (!left_type->typeEqual(right_type) || left_type->getID() != TYPE_ID::INT) {
            std::cout << "[Error]: Cannot greater than of " << left_type->getName() << " and " << right_type->getName() << std::endl;
            exit(1);
        }
        
        return std::make_shared<Type_Bool>();
    }

    llvm::Value* genCode(Environment &env, GeneratedCode &code, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        llvm::Value* left_code = left->genCode(env, code, class_desc, method_desc);
        llvm::Value* right_code = right->genCode(env, code, class_desc, method_desc);

        // temps are on the stack, so if LHS or RHS is an id, we need to get the value
        if (left_code->getType()->isPointerTy())
            left_code = code.getBuilder().CreateLoad(left_code->getType()->getPointerElementType(), left_code);

        if (right_code->getType()->isPointerTy())
            right_code = code.getBuilder().CreateLoad(right_code->getType()->getPointerElementType(), right_code);

        return code.getBuilder().CreateICmpSGT(left_code, right_code);
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

    llvm::Value* genCode(Environment &env, GeneratedCode &code, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        llvm::Value* expr_code = expr->genCode(env, code, class_desc, method_desc);

        // temps are on the stack, so if LHS or RHS is an id, we need to get the value
        if (expr_code->getType()->isPointerTy())
            expr_code = code.getBuilder().CreateLoad(expr_code->getType()->getPointerElementType(), expr_code);

        return code.getBuilder().CreateNeg(expr_code);
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

        if (type->getID() != TYPE_ID::BOOL) {
            std::cout << "[Error]: Cannot logically negate " << type->getName() << std::endl;
            exit(1);
        }
        
        return type;
    }

    llvm::Value* genCode(Environment &env, GeneratedCode &code, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        llvm::Value* expr_code = expr->genCode(env, code, class_desc, method_desc);

        // temps are on the stack, so if LHS or RHS is an id, we need to get the value
        if (expr_code->getType()->isPointerTy())
            expr_code = code.getBuilder().CreateLoad(expr_code->getType()->getPointerElementType(), expr_code);

        return code.getBuilder().CreateNot(expr_code);
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

    llvm::Value* genCode(Environment &env, GeneratedCode &code, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        return code.getNewLiteral(integer);
    }

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

    llvm::Value* genCode(Environment &env, GeneratedCode &code, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        return code.getNewLiteral(boolean);
    }

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

    void checkTypes(Environment &env, Descriptor_Class &class_desc, Descriptor_Method &method_desc) {
        // size - 1 to account for "this"
        auto args = method_desc.getArgumentDescriptors();
        if (args.size() - 1 != expressions.size()) {
            std::cout << "[Error]: Method call to " << method_desc.getName() << " expected " << args.size() - 1 << " arguments, but got " << expressions.size() << std::endl;
            exit(1);
        }

        for (size_t i = 0; i < expressions.size(); i++) {
            // args[i + 1] to account for "this" being the first argument
            auto expr_type = expressions[i]->getType(env, class_desc, method_desc);
            if (!expr_type->typeEqual(args[i + 1]->getType())) {
                std::cout << "[Error]: Method call to " << method_desc.getName() << " expected the argument at position " << i << " to be of type " << args[i + 1]->getName() << " but got argument of type " << expr_type->getName() << std::endl;
                exit(1);
            }
        }
    }

    std::vector<llvm::Value*> genCode(Environment &env, GeneratedCode &code, Descriptor_Class &class_desc, Descriptor_Method &method_desc) {
        std::vector<llvm::Value*> toRet;

        for (auto& node : expressions) {
            llvm::Value *value = node->genCode(env, code, class_desc, method_desc);

            // expression can be an identifier in the local scope which is a double pointer
            if (value->getType()->isPointerTy() && value->getType()->getPointerElementType()->isPointerTy())
                value = code.getBuilder().CreateLoad(value->getType()->getPointerElementType(), value);

            toRet.push_back(value);
        }

        return toRet;
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
        auto calling_class_desc = env.getClassDescriptor(type);
        calling_class_desc->getType()->pushScope(env);
        auto constructor_desc = env.getMethodDescriptor(type);
        calling_class_desc->getType()->popScope(env);

        actuals->checkTypes(env, class_desc, *constructor_desc);

        return calling_class_desc->getType();
    }

    static llvm::Value* genCodeCreateObject(GeneratedCode &code, Descriptor_Class &obj_class, std::vector<llvm::Value*> parameters) {
        auto constructor_desc = obj_class.getConstructor();

        llvm::Type* ptr_type = llvm::Type::getInt32Ty(code.getContext());
        llvm::Type* type = obj_class.getType()->getLLVMType(code);
        //llvm::Constant* size = llvm::ConstantExpr::getBitCast(llvm::ConstantExpr::getSizeOf(type), llvm::Type::getInt32Ty(code.getContext()));
        int real_size = code.getModule().getDataLayout().getStructLayout((llvm::StructType*) type)->getSizeInBytes();
        llvm::ConstantInt* size = llvm::ConstantInt::get(llvm::Type::getInt32Ty(code.getContext()), real_size);

        auto inst = llvm::CallInst::CreateMalloc(code.getBuilder().GetInsertBlock(), ptr_type, type, size, nullptr, nullptr, "");
        code.getBuilder().Insert(inst);

        // store the vtable
        llvm::Type *func_ptr_type = llvm::PointerType::get(llvm::IntegerType::get(code.getContext(), 32), 0);
        llvm::Value* obj_vtable = code.getBuilder().CreateConstGEP2_32(inst->getType()->getPointerElementType(), inst, 0, 0);
        // this cast is to ignore the size of the array that is the vtable (rather than figure it out explicitly)
        obj_vtable = code.getBuilder().CreateBitCast(obj_vtable, llvm::PointerType::get(obj_class.getVtable()->getType(), 0));
        code.getBuilder().CreateStore(obj_class.getVtable(), obj_vtable);

        parameters.insert(parameters.begin(), inst);

        code.getBuilder().CreateCall(constructor_desc->getLLVMFunction()->getFunctionType(), constructor_desc->getLLVMFunction(), parameters);
        return inst;
    }

    llvm::Value* genCode(Environment &env, GeneratedCode &code, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        auto calling_class_desc = env.getClassDescriptor(type);
        calling_class_desc->getType()->pushScope(env);
            auto parameters = actuals->genCode(env, code, class_desc, method_desc);
        calling_class_desc->getType()->popScope(env);

        return genCodeCreateObject(code, *calling_class_desc, parameters);
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
    std::unique_ptr<ASTNode_Type> type_ast;
    std::unique_ptr<ASTNode_Expr> expr;

public:
    ASTNode_Expr_New_Array(ASTNode_Type *type, ASTNode_Expr *expr)
        : type_ast(type), expr(expr)
    {

    }

    std::shared_ptr<Type> getType(Environment &env, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        auto arr_type = std::make_shared<Type_Array>(type_ast->getType(env));
        auto expr_type = expr->getType(env, class_desc, method_desc);

        if (expr_type->getID() != TYPE_ID::INT) {
            std::cout << "[Error]: Array cannot be accessed by a non-integer. Currently attempting: " << expr_type->getName() << std::endl;
            exit(1);
        }

        return arr_type;
    }

    llvm::Value* genCode(Environment &env, GeneratedCode &code, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        llvm::Type* ptr_type = llvm::Type::getInt32Ty(code.getContext());
        llvm::Type* type = type_ast->getType(env)->getLLVMType(code);
        llvm::Value* expr_value = expr->genCode(env, code, class_desc, method_desc);

        auto inst = llvm::CallInst::CreateMalloc(code.getBuilder().GetInsertBlock(), ptr_type, type, expr_value, nullptr, nullptr, "");

        return inst;
    }

    void print() override {
        std::cout << "new int [ ";
        expr->print();
        std::cout << " ]";
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_Expr_New_Array" << std::endl;
        type_ast->printTree(level + 1);
        expr->printTree(level + 1);
    }
};

class ASTNode_Statement : public ASTNode {
public:
    virtual void pass_3(Environment &env, Descriptor_Class &class_desc, Descriptor_Method &method_desc) = 0;
    virtual void genCode(Environment &env, GeneratedCode &code, Descriptor_Class &class_desc, Descriptor_Method &method_desc) = 0;
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

    void genCode(Environment &env, GeneratedCode &code, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        expr->genCode(env, code, class_desc, method_desc);
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
    std::unique_ptr<ASTNode_Type> type_ast;
    std::string name;

public:
    ASTNode_Statement_VariableDeclaration(ASTNode_Type *type_ast, const char* name_c)
        : type_ast(type_ast), name(name_c)
    {

    }

    void pass_3(Environment &env, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        auto type = type_ast->getType(env);
        if (type->getID() == TYPE_ID::VOID) {
            std::cout << "[Error]: Cannot declare local variable to be of type void" << std::endl;
            exit(1);
        }

        auto desc = std::make_shared<Descriptor_Variable>(name, type);
        env.getTopScope()->setVariableDescriptor(name, desc);
        method_desc.addLocalVariable(desc);
    }

    void genCode(Environment &env, GeneratedCode &code, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        
    }

    void print() override {
        type_ast->print();
        std::cout << " " << name << ";" << std::endl;
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_Statement_VariableDeclaration: " << name << std::endl;
        type_ast->printTree(level + 1);
    }
};

class ASTNode_Statement_Empty : public ASTNode_Statement {
public:
    ASTNode_Statement_Empty() {

    }

    void pass_3(Environment &env, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {

    }

    void genCode(Environment &env, GeneratedCode &code, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {

    }

    void print() override {
        std::cout << ";" << std::endl;
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_Statement_Empty" << std::endl;
    }
};

class ASTNode_Statement_Print_Int : public ASTNode_Statement {
private:
    std::unique_ptr<ASTNode_Expr> expr;

public:
    ASTNode_Statement_Print_Int(ASTNode_Expr *expr)
        : expr(expr)
    {

    }

    void pass_3(Environment &env, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        auto expr_type = expr->getType(env, class_desc, method_desc);
        if (expr_type->getID() != TYPE_ID::INT) {
            std::cout << "[Error]: print INT expects and int, got: " << expr_type->getName() << std::endl;
            exit(1);
        }
    }

    void genCode(Environment &env, GeneratedCode &code, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        llvm::Value *int_str = code.getBuilder().CreateGlobalStringPtr("%d\n");
        llvm::Value *expr_value = expr->genCode(env, code, class_desc, method_desc);
        std::vector<llvm::Value*> args = { int_str, expr_value };

        std::vector<llvm::Type *> printfArgsTypes({llvm::Type::getInt8PtrTy(code.getContext())});
        llvm::FunctionType *printfType = llvm::FunctionType::get(llvm::Type::getInt32PtrTy(code.getContext()), printfArgsTypes, true);
        auto *printfFunc = code.getModule().getOrInsertFunction("printf", printfType).getCallee();

        code.getBuilder().CreateCall(printfFunc, args);
    }

    void print() override {
        std::cout << "PRINT_INT (";
        expr->print();
        std::cout << ")" << std::endl;
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_Statement_Print_Int" << std::endl;
        expr->printTree(level + 1);
    }
};

class ASTNode_Statement_Print_Bool : public ASTNode_Statement {
private:
    std::unique_ptr<ASTNode_Expr> expr;

public:
    ASTNode_Statement_Print_Bool(ASTNode_Expr *expr)
        : expr(expr)
    {

    }

    void pass_3(Environment &env, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        auto expr_type = expr->getType(env, class_desc, method_desc);
        if (expr_type->getID() != TYPE_ID::BOOL) {
            std::cout << "[Error]: print BOOL expects and int, got: " << expr_type->getName() << std::endl;
            exit(1);
        }
    }

    void genCode(Environment &env, GeneratedCode &code, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        llvm::Value *int_str = code.getBuilder().CreateGlobalStringPtr("%d\n");
        llvm::Value *expr_value = expr->genCode(env, code, class_desc, method_desc);
        std::vector<llvm::Value*> args = { expr_value };

        std::vector<llvm::Type *> printfArgsTypes({llvm::Type::getInt8PtrTy(code.getContext())});
        llvm::FunctionType *printfType = llvm::FunctionType::get(llvm::Type::getInt32PtrTy(code.getContext()), printfArgsTypes, true);
        auto *printfFunc = code.getModule().getOrInsertFunction("printf", printfType).getCallee();

        code.getBuilder().CreateCall(printfFunc, args);
    }

    void print() override {
        std::cout << "PRINT_BOOL (";
        expr->print();
        std::cout << ")" << std::endl;
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_Statement_Print_Bool" << std::endl;
        expr->printTree(level + 1);
    }
};

class ASTNode_Statement_Print_Line : public ASTNode_Statement {
public:
    ASTNode_Statement_Print_Line()
    {

    }

    void pass_3(Environment &env, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {

    }

    void genCode(Environment &env, GeneratedCode &code, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        llvm::Value *int_str = code.getBuilder().CreateGlobalStringPtr("\n");

        std::vector<llvm::Type *> printfArgsTypes({llvm::Type::getInt8PtrTy(code.getContext())});
        llvm::FunctionType *printfType = llvm::FunctionType::get(llvm::Type::getInt32PtrTy(code.getContext()), printfArgsTypes, true);
        auto *printfFunc = code.getModule().getOrInsertFunction("printf", printfType).getCallee();

        code.getBuilder().CreateCall(printfFunc, {});
    }

    void print() override {
        std::cout << "PRINT_LINE(";
        std::cout << ")" << std::endl;
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_Statement_Print_Line" << std::endl;
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

    void genCode(Environment &env, GeneratedCode &code, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        llvm::Value *toRet = expr->genCode(env, code, class_desc, method_desc);
        if (toRet->getType()->isPointerTy()) {
            toRet = code.getBuilder().CreateLoad(toRet->getType()->getPointerElementType(), toRet);
        }

        code.getBuilder().CreateRet(toRet);
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

class ASTNode_Statement_ReturnVoid : public ASTNode_Statement {
public:
    void pass_3(Environment &env, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        if (method_desc.getReturnType()->getID() != TYPE_ID::VOID) {
            std::cout << "[Error]: the function " << method_desc.getName() << " has return type " << method_desc.getReturnType()->getName() << " but used a void return!" << std::endl;
            exit(1);
        }
    }

    void genCode(Environment &env, GeneratedCode &code, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        code.getBuilder().CreateRetVoid();
    }

    void print() override {
        std::cout << "return ";
        std::cout << ";" << std::endl;
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_Statement_ReturnVoid" << std::endl;
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

    void genCode(Environment &env, GeneratedCode &code, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        for (auto& node : nodes)
            node->genCode(env, code, class_desc, method_desc);
        if (method_desc.getReturnType()->getID() == TYPE_ID::VOID)
            code.getBuilder().CreateRetVoid();
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

    void genCode(Environment &env, GeneratedCode &code, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        llvm::BasicBlock *after_block = llvm::BasicBlock::Create(code.getContext(), "after", method_desc.getLLVMFunction());
        llvm::BasicBlock *while_do_block = llvm::BasicBlock::Create(code.getContext(), "while_do", method_desc.getLLVMFunction(), after_block);
        llvm::BasicBlock *while_cond_block = llvm::BasicBlock::Create(code.getContext(), "while_cond", method_desc.getLLVMFunction(), while_do_block);

        code.getBuilder().SetInsertPoint(while_cond_block);
        llvm::Value* cmp_expr = condition_expr->genCode(env, code, class_desc, method_desc);
        code.getBuilder().CreateCondBr(cmp_expr, while_do_block, after_block);

        code.getBuilder().SetInsertPoint(while_do_block);
        statement->genCode(env, code, class_desc, method_desc);
        code.getBuilder().CreateBr(while_cond_block);

        code.getBuilder().SetInsertPoint(after_block);
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

    void genCode(Environment &env, GeneratedCode &code, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        llvm::BasicBlock *after_block = llvm::BasicBlock::Create(code.getContext(), "after", method_desc.getLLVMFunction());
        llvm::BasicBlock *if_block = llvm::BasicBlock::Create(code.getContext(), "if", method_desc.getLLVMFunction(), after_block);

        llvm::Value* cmp_expr = condition_expr->genCode(env, code, class_desc, method_desc);
        code.getBuilder().CreateCondBr(cmp_expr, if_block, after_block);

        code.getBuilder().SetInsertPoint(if_block);
        statement->genCode(env, code, class_desc, method_desc);
        code.getBuilder().CreateBr(after_block);

        code.getBuilder().SetInsertPoint(after_block);
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

    void genCode(Environment &env, GeneratedCode &code, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        llvm::BasicBlock *after_block = llvm::BasicBlock::Create(code.getContext(), "after", method_desc.getLLVMFunction());
        llvm::BasicBlock *else_block = llvm::BasicBlock::Create(code.getContext(), "else", method_desc.getLLVMFunction(), after_block);
        llvm::BasicBlock *if_block = llvm::BasicBlock::Create(code.getContext(), "if", method_desc.getLLVMFunction(), else_block);

        llvm::Value* cmp_expr = condition_expr->genCode(env, code, class_desc, method_desc);
        code.getBuilder().CreateCondBr(cmp_expr, if_block, else_block);

        code.getBuilder().SetInsertPoint(if_block);
        statement_true->genCode(env, code, class_desc, method_desc);
        code.getBuilder().CreateBr(after_block);

        code.getBuilder().SetInsertPoint(else_block);
        statement_false->genCode(env, code, class_desc, method_desc);
        code.getBuilder().CreateBr(after_block);

        code.getBuilder().SetInsertPoint(after_block);
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
        return env.getVariableDescriptor(id)->getType();
    }

    llvm::Value* genCode(Environment &env, GeneratedCode &code, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        return env.getVariableDescriptor(id)->getLLVMValue();
    }

    void print() override {
        std::cout << id;
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_LValue_ID: " << id << std::endl;
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

        callee_type->pushScope(env);
            std::shared_ptr<Descriptor_Method> desc = env.getMethodDescriptor(id);
        callee_type->popScope(env);

        actuals->checkTypes(env, class_desc, *desc);

        return desc->getReturnType();
    }

    static llvm::Value* genVtableFuncCall(GeneratedCode &code, llvm::Value *obj, Descriptor_Method &calling_method_desc, std::vector<llvm::Value*> parameters) {
        size_t vtable_index = calling_method_desc.getVtableOffset();
 
        parameters.insert(parameters.begin(), obj);

        llvm::Type *func_ptr_type = llvm::PointerType::get(llvm::IntegerType::get(code.getContext(), 32), 0);

        llvm::Value* adrVTBL = code.getBuilder().CreateConstGEP2_32(obj->getType()->getPointerElementType(), obj, 0, 0);
        llvm::Value* basVTBL = code.getBuilder().CreateLoad(adrVTBL->getType()->getPointerElementType(), adrVTBL);
        llvm::Value* adrEntr = code.getBuilder().CreateConstGEP2_32(basVTBL->getType()->getPointerElementType(), basVTBL, 0, vtable_index);
        llvm::Value* mthPtr  = code.getBuilder().CreateLoad(func_ptr_type, adrEntr);
        llvm::Type*  mthTy   = calling_method_desc.getLLVMFunction()->getType();
        llvm::Value* func    = code.getBuilder().CreateBitCast(mthPtr, mthTy);

        return code.getBuilder().CreateCall(calling_method_desc.getLLVMFunction()->getFunctionType(), func, parameters);
    }

    llvm::Value* genCode(Environment &env, GeneratedCode &code, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        std::shared_ptr<Type> callee_type = obj_lvalue->getType(env, class_desc, method_desc);
        callee_type->pushScope(env);
            auto calling_method_desc = env.getMethodDescriptor(id);
        callee_type->popScope(env);
        
        llvm::Value *obj = obj_lvalue->genCode(env, code, class_desc, method_desc);
        obj = code.getBuilder().CreateLoad(obj->getType()->getPointerElementType(), obj);
        std::vector<llvm::Value*> parameters = actuals->genCode(env, code, class_desc, method_desc);

        return genVtableFuncCall(code, obj, *calling_method_desc, parameters);
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
        auto calling_method_desc = env.getMethodDescriptor(id);

        actuals->checkTypes(env, class_desc, *calling_method_desc);

        // this method name should be in scope
        return calling_method_desc->getReturnType();
    }

    llvm::Value* genCode(Environment &env, GeneratedCode &code, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        auto obj = env.getVariableDescriptor("this")->getLLVMValue();
        auto calling_method_desc = env.getMethodDescriptor(id);
        
        obj = code.getBuilder().CreateLoad(obj->getType()->getPointerElementType(), obj);
        std::vector<llvm::Value*> parameters = actuals->genCode(env, code, class_desc, method_desc);

        return ASTNode_LValue_Obj_MethodCall::genVtableFuncCall(code, obj, *calling_method_desc, parameters);
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

        callee_type->pushScope(env);
            std::shared_ptr<Descriptor_Variable> desc = env.getVariableDescriptor(id);
        callee_type->popScope(env);

        return desc->getType();
    }

    llvm::Value* genCode(Environment &env, GeneratedCode &code, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        llvm::Value *obj_ptr = obj_lvalue->genCode(env, code, class_desc, method_desc);
        if (obj_ptr->getType()->getPointerElementType()->isPointerTy())
            obj_ptr = code.getBuilder().CreateLoad(obj_ptr->getType()->getPointerElementType(), obj_ptr);

        std::shared_ptr<Type> callee_type = obj_lvalue->getType(env, class_desc, method_desc);
        callee_type->pushScope(env);
            auto var_desc = env.getVariableDescriptor(id);
        callee_type->popScope(env);
        
        //int offset = code.getModule().getDataLayout().getStructLayout((llvm::StructType*) obj_ptr->getType()->getPointerElementType())->getElementOffset(var_desc->getStructIndex());
        //return code.getBuilder().CreateConstGEP2_32(obj_ptr->getType()->getPointerElementType(), obj_ptr, 0, offset);

        return code.getBuilder().CreateConstGEP2_32(obj_ptr->getType()->getPointerElementType(), obj_ptr, 0, var_desc->getStructIndex());
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

    llvm::Value* genCode(Environment &env, GeneratedCode &code, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        llvm::Value* arr_ptr = lvalue->genCode(env, code, class_desc, method_desc);
        arr_ptr = code.getBuilder().CreateLoad(arr_ptr);

        llvm::Value* expr_value = expr->genCode(env, code, class_desc, method_desc);
        
        llvm::Value* size = llvm::ConstantInt::get(llvm::Type::getInt32Ty(code.getContext()), code.getModule().getDataLayout().getTypeAllocSize(arr_ptr->getType()->getArrayElementType()));

        llvm::Value *offset = code.getBuilder().CreateMul(size, expr_value);
        llvm::Value* sum = code.getBuilder().CreateAdd(arr_ptr, offset);

        return code.getBuilder().CreateLoad(sum);
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

    llvm::Value* genCode(Environment &env, GeneratedCode &code, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        return env.getVariableDescriptor("this")->getLLVMValue();
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

        if (!lvalue_type->isSubtype(expr_type)) {
            std::cout << "[Error]: Cannot assign to a type " << lvalue_type->getName() << " with type " << expr_type->getName() << std::endl;
            exit(1);
        }
    }

    void genCode(Environment &env, GeneratedCode &code, Descriptor_Class &class_desc, Descriptor_Method &method_desc) override {
        llvm::Value *expr_code = expr->genCode(env, code, class_desc, method_desc);

        // locals are pointers to somewhere on stack, must dereference
        if (expr_code->getType()->isPointerTy() && !expr_code->getType()->getPointerElementType()->isStructTy())
            expr_code = code.getBuilder().CreateLoad(expr_code->getType()->getPointerElementType(), expr_code);

        code.getBuilder().CreateStore(expr_code, lvalue->genCode(env, code, class_desc, method_desc));
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
        auto desc = std::make_shared<Descriptor_Variable>(id, type->getType(env));
        env.getTopScope()->setVariableDescriptor(id, desc);
        method_descriptor->addArgumentDescriptor(desc);
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
    virtual void pass_2(Environment &env, Descriptor_Class &class_desc, GeneratedCode &code) = 0;
    virtual void pass_3(Environment &env, Descriptor_Class &class_desc) = 0;

    virtual void genCode(Environment &env, GeneratedCode &code, Descriptor_Class &class_desc) = 0;
};

class ASTNode_MemberDeclaration_Variable : public ASTNode_MemberDeclaration {
private:
    std::unique_ptr<ASTNode_Type> type_ast;
    std::string id;

public:
    ASTNode_MemberDeclaration_Variable(ASTNode_Type *type_ast, const char *id_c)
        : type_ast(type_ast), id(id_c)
    {

    }

    void pass_2(Environment &env, Descriptor_Class &class_desc, GeneratedCode &code) override {
        auto type = type_ast->getType(env);
        if (type->getID() == TYPE_ID::VOID) {
            std::cout << "[Error]: Variable cannot be declared to have type void" << std::endl;
            exit(1);
        }

        auto desc = std::make_shared<Descriptor_Variable>(id, type);
        env.getTopScope()->setVariableDescriptor(id, desc);
        class_desc.addField(desc);
    }

    void pass_3(Environment &env, Descriptor_Class &class_desc) override {

    }

    void genCode(Environment &env, GeneratedCode &code, Descriptor_Class &class_desc) override {
        
    }

    void print() override {
        type_ast->print();
        std::cout << id << ";" << std::endl;
    }

    void printTree(int level) override {
        printIndent(level);
        std::cout << "ASTNode_MemberDeclaration_Variable: " << id << std::endl;
        type_ast->printTree(level + 1);
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

    void pass_2(Environment &env, Descriptor_Class &class_desc, GeneratedCode &code) override {
        desc = std::make_shared<Descriptor_Method>(id, type->getType(env));
        env.getTopScope()->setMethodDescriptor(id, desc);
        class_desc.addMethod(desc);

        env.pushScope(argument_scope);
            // this
            auto this_desc = std::make_shared<Descriptor_Variable>("this", class_desc.getType());
            env.getTopScope()->setVariableDescriptor("this", this_desc);
            desc->addArgumentDescriptor(this_desc);

            // actual formals
            formals->pass_2(env, desc);

            std::vector<llvm::Type*> argument_types;
            for (auto arg : desc->getArgumentDescriptors()) {
                llvm::Type *type = arg->getType()->getLLVMType(code);
                if (type->isStructTy())
                    type = llvm::PointerType::getUnqual(type);
                argument_types.push_back(type);
            }

            llvm::FunctionType *FT = llvm::FunctionType::get(desc->getReturnType()->getLLVMType(code), argument_types, false);
            llvm::Function *F = llvm::Function::Create(FT, llvm::Function::ExternalLinkage, class_desc.getName() + "_" + id, code.getModule());
            desc->setLLVMFuntion(F);

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

    void genCode(Environment &env, GeneratedCode &code, Descriptor_Class &class_desc) override {
        llvm::Function *F = desc->getLLVMFunction();
        llvm::BasicBlock *BB = llvm::BasicBlock::Create(code.getContext(), "entry", F);
        code.getBuilder().SetInsertPoint(BB);

        desc->setLLVMFuntion(F);
        
        // *everything* goes on the stack, even the arguments...
        auto args = desc->getArgumentDescriptors();
        for (size_t i = 0; i < F->arg_size(); i++) {
            auto local_arg = desc->getArgumentDescriptors()[i];
            auto llvm_arg = F->getArg(i);
            
            local_arg->setLLVMValue(code.getBuilder().CreateAlloca(llvm_arg->getType(), nullptr, local_arg->getName()));
            code.getBuilder().CreateStore(llvm_arg, local_arg->getLLVMValue());
        }

        auto locals = desc->getLocalVariableDescriptors();
        for (auto local : locals) {
            llvm::Type *type = local->getType()->getLLVMType(code);
            if (type->isStructTy())
                type = llvm::PointerType::getUnqual(type);

            local->setLLVMValue(code.getBuilder().CreateAlloca(type, nullptr, local->getName()));
        }

        env.pushScope(argument_scope);
        env.pushScope(body_scope);
            body->genCode(env, code, class_desc, *desc);
        env.popScope();
        env.popScope();
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

    void pass_2(Environment &env, Descriptor_Class &class_desc, GeneratedCode &code) override {
        this->desc = std::make_shared<Descriptor_Constructor>(id);
        env.getTopScope()->setMethodDescriptor(id, desc);
        class_desc.setConstructor(desc);

        env.pushScope(argument_scope);
            // this
            auto this_desc = std::make_shared<Descriptor_Variable>("this", class_desc.getType());
            env.getTopScope()->setVariableDescriptor("this", this_desc);
            desc->addArgumentDescriptor(this_desc);

            formals->pass_2(env, desc);

            std::vector<llvm::Type*> argument_types;
            for (auto arg : desc->getArgumentDescriptors()) {
                llvm::Type *type = arg->getType()->getLLVMType(code);
                if (type->isStructTy())
                    type = llvm::PointerType::getUnqual(type);
                argument_types.push_back(type);
            }

            llvm::FunctionType *FT = llvm::FunctionType::get(desc->getReturnType()->getLLVMType(code), argument_types, false);
            llvm::Function *F = llvm::Function::Create(FT, llvm::Function::ExternalLinkage, class_desc.getName() + "_" + id, code.getModule());
            desc->setLLVMFuntion(F);
        env.popScope();
    }

    void pass_3(Environment &env, Descriptor_Class &class_desc) override {
        env.pushScope(argument_scope);
        env.pushScope(body_scope);
            body->pass_3(env, class_desc, *desc);
        env.popScope();
        env.popScope();
    }

    void genCode(Environment &env, GeneratedCode &code, Descriptor_Class &class_desc) override {
        llvm::Function *F = desc->getLLVMFunction();
        llvm::BasicBlock *BB = llvm::BasicBlock::Create(code.getContext(), "entry", F);
        code.getBuilder().SetInsertPoint(BB);
        
        // *everything* goes on the stack, even the arguments...
        auto args = desc->getArgumentDescriptors();
        for (size_t i = 0; i < F->arg_size(); i++) {
            auto local_arg = desc->getArgumentDescriptors()[i];
            auto llvm_arg = F->getArg(i);
            
            local_arg->setLLVMValue(code.getBuilder().CreateAlloca(llvm_arg->getType(), nullptr, local_arg->getName()));
            code.getBuilder().CreateStore(llvm_arg, local_arg->getLLVMValue());
        }

        auto locals = desc->getLocalVariableDescriptors();
        for (auto local : locals) {
            llvm::Type *type = local->getType()->getLLVMType(code);
            if (type->isStructTy())
                type = llvm::PointerType::getUnqual(type);

            local->setLLVMValue(code.getBuilder().CreateAlloca(type, nullptr, local->getName()));
        }

        env.pushScope(argument_scope);
        env.pushScope(body_scope);
            body->genCode(env, code, class_desc, *desc);
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

    void pass_2(Environment &env, Descriptor_Class &class_desc, GeneratedCode &code) {
        for (auto& decl : declarations)
            decl->pass_2(env, class_desc, code);
    }

    void pass_3(Environment &env, Descriptor_Class &class_desc) {
        for (auto& decl : declarations)
            decl->pass_3(env, class_desc);
    }

    void genCode(Environment &env, GeneratedCode &code, Descriptor_Class &class_desc) {
        for (auto& decl : declarations)
            decl->genCode(env, code, class_desc);
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

    virtual void pass_2(Environment &env, GeneratedCode &code) {
        this->desc->getType()->pushScope(env);
            declarations->pass_2(env, *desc, code);
            //std::cout << *scope << std::endl;
            std::cout << *desc << std::endl << std::endl;
        this->desc->getType()->popScope(env);
        this->desc->genLLVMType(code);
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

    void genCode(Environment &env, GeneratedCode &code) {
        this->desc->genCode(code);

        this->desc->getType()->pushScope(env);
            declarations->genCode(env, code, *desc);
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

        desc->setParentClass(parent_desc);
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

    void pass_2(Environment &env, GeneratedCode &code) {
        env.pushScope(scope);
            for (auto& clazz : classes)
                clazz->pass_2(env, code);
        env.popScope();

        //std::cout << *scope << std::endl;
    }

    void pass_3(Environment &env) {
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

    void genCode(Environment &env, GeneratedCode &code) {
        // Make the function type:  double(double,double) etc.

        //llvm::FunctionType *FT = llvm::FunctionType::get(llvm::Type::getVoidTy(code.getContext()), {}, false);
        //llvm::Function *F = llvm::Function::Create(FT, llvm::Function::ExternalLinkage, "Main", code.getModule());

        //llvm::BasicBlock *BB = llvm::BasicBlock::Create(code.getContext(), "entry", F);
        //code.getBuilder().SetInsertPoint(BB);
        env.pushScope(scope);
            for (auto& clazz : classes)
                clazz->genCode(env, code);

            llvm::FunctionType *FT = llvm::FunctionType::get(llvm::IntegerType::getInt32Ty(code.getContext()), {}, false);
            llvm::Function *F = llvm::Function::Create(FT, llvm::Function::ExternalLinkage, "main", code.getModule());
            llvm::BasicBlock *BB = llvm::BasicBlock::Create(code.getContext(), "entry", F);
            code.getBuilder().SetInsertPoint(BB);

            auto class_desc = env.getClassDescriptor("Main");
            ASTNode_Expr_New_Obj::genCodeCreateObject(code, *class_desc, {});

            code.getBuilder().CreateRet(code.getNewLiteral(0));
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

    void pass_2(Environment &env, GeneratedCode &code) {
        root.pass_2(env, code);
    }

    void pass_3(Environment &env) { 
        root.pass_3(env);
    }

    void genCode(Environment &env, GeneratedCode &code) {
        root.genCode(env, code);
    }
};
