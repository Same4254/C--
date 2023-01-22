#pragma once

#include <iostream>
#include <vector>
#include <memory>

class ASTNode {
public:
	virtual ~ASTNode() = default;

    virtual void print() = 0;
};

class ASTNode_Expr_Times : public ASTNode {
private:
	ASTNode* left;
	ASTNode* right;

public:
    ASTNode_Expr_Times(ASTNode* left, ASTNode* right)
        : left(left), right(right)
    {

    }

    void print() override {
        left->print();
        std::cout << " * ";
        right->print();
    }
};

class ASTNode_Expr_Divide : public ASTNode {
private:
	ASTNode* left;
	ASTNode* right;

public:
    ASTNode_Expr_Divide(ASTNode* left, ASTNode* right)
        : left(left), right(right)
    {

    }

    void print() override {
        left->print();
        std::cout << " / ";
        right->print();
    }
};

class ASTNode_Expr_Plus : public ASTNode {
private:
	ASTNode* left;
	ASTNode* right;

public:
    ASTNode_Expr_Plus(ASTNode* left, ASTNode* right)
        : left(left), right(right)
    {

    }

    void print() override {
        left->print();
        std::cout << " + ";
        right->print();
    }
};

class ASTNode_Expr_Minus : public ASTNode {
private:
	ASTNode* left;
	ASTNode* right;

public:
    ASTNode_Expr_Minus(ASTNode* left, ASTNode* right)
        : left(left), right(right)
    {

    }

    void print() override {
        left->print();
        std::cout << " - ";
        right->print();
    }
};

class ASTNode_Expr_Parenthesis : public ASTNode {
private:
	ASTNode* expr;

public:
    ASTNode_Expr_Parenthesis(ASTNode* expr)
        : expr(expr)
    {

    }

    void print() override {
        std::cout << "( ";
        expr->print();
        std::cout << " )";
    }
};

class ASTNode_Expr_And : public ASTNode {
private:
	ASTNode* left;
	ASTNode* right;

public:
    ASTNode_Expr_And(ASTNode* left, ASTNode* right)
        : left(left), right(right)
    {

    }

    void print() override {
        left->print();
        std::cout << " && ";
        right->print();
    }
};

class ASTNode_Expr_Or : public ASTNode {
private:
	ASTNode* left;
	ASTNode* right;

public:
    ASTNode_Expr_Or(ASTNode* left, ASTNode* right)
        : left(left), right(right)
    {

    }

    void print() override {
        left->print();
        std::cout << " || ";
        right->print();
    }
};

class ASTNode_Expr_Equivalent : public ASTNode {
private:
	ASTNode* left;
	ASTNode* right;

public:
    ASTNode_Expr_Equivalent(ASTNode* left, ASTNode* right)
        : left(left), right(right)
    {

    }

    void print() override {
        left->print();
        std::cout << " == ";
        right->print();
    }
};

class ASTNode_Expr_IsNotEqual : public ASTNode {
private:
	ASTNode* left;
	ASTNode* right;

public:
    ASTNode_Expr_IsNotEqual(ASTNode* left, ASTNode* right)
        : left(left), right(right)
    {

    }

    void print() override {
        left->print();
        std::cout << " != ";
        right->print();
    }
};

class ASTNode_Expr_LessThanOrEqual : public ASTNode {
private:
	ASTNode* left;
	ASTNode* right;

public:
    ASTNode_Expr_LessThanOrEqual(ASTNode* left, ASTNode* right)
        : left(left), right(right)
    {

    }

    void print() override {
        left->print();
        std::cout << " <= ";
        right->print();
    }
};

class ASTNode_Expr_LessThan : public ASTNode {
private:
	ASTNode* left;
	ASTNode* right;

public:
    ASTNode_Expr_LessThan(ASTNode* left, ASTNode* right)
        : left(left), right(right)
    {

    }

    void print() override {
        left->print();
        std::cout << " < ";
        right->print();
    }
};

class ASTNode_Expr_GreaterThanOrEqual : public ASTNode {
private:
	ASTNode* left;
	ASTNode* right;

public:
    ASTNode_Expr_GreaterThanOrEqual(ASTNode* left, ASTNode* right)
        : left(left), right(right)
    {

    }

    void print() override {
        left->print();
        std::cout << " >= ";
        right->print();
    }
};

class ASTNode_Expr_GreaterThan : public ASTNode {
private:
	ASTNode* left;
	ASTNode* right;

public:
    ASTNode_Expr_GreaterThan(ASTNode* left, ASTNode* right)
        : left(left), right(right)
    {

    }

    void print() override {
        left->print();
        std::cout << " > ";
        right->print();
    }
};

class ASTNode_Expr_UnaryMinus : public ASTNode {
private:
	ASTNode* expr;

public:
    ASTNode_Expr_UnaryMinus(ASTNode* expr)
        : expr(expr)
    {

    }

    void print() override {
        std::cout << "-";
        expr->print();
    }
};

class ASTNode_Expr_BooleanNegate : public ASTNode {
private:
	ASTNode* expr;

public:
    ASTNode_Expr_BooleanNegate(ASTNode* expr)
        : expr(expr)
    {

    }

    void print() override {
        std::cout << "!";
        expr->print();
    }
};

class ASTNode_Expr_Integer : public ASTNode {
private:
    int64_t integer;

public:
    ASTNode_Expr_Integer(int64_t integer)
        : integer(integer)
    {

    }

    void print() override {
        std::cout << integer;
    }
};

class ASTNode_Expr_Boolean : public ASTNode {
private:
    bool boolean;

public:
    ASTNode_Expr_Boolean(bool boolean)
        : boolean(boolean)
    {

    }

    void print() override {
        std::cout << (boolean ? "true" : "false");
    }
};

class ASTNode_Actuals : public ASTNode {
private:
    std::vector<ASTNode*> expressions;

public:
    ASTNode_Actuals() {
    
    }

    void AddExpression(ASTNode *expr) {
		expressions.insert(expressions.begin(), expr);
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
};

class ASTNode_Expr_New_Obj : public ASTNode {
private:
    ASTNode_Actuals* actuals;
    std::string type;

public:
    ASTNode_Expr_New_Obj(ASTNode_Actuals* actuals, const char *type_c)
        : actuals(actuals), type(type_c)
    {

    }

    void print() override {
        std::cout << "new " << type << "( ";
        actuals->print();
        std::cout << " )";
    }
};

class ASTNode_Expr_New_Array_Int : public ASTNode {
private:
	ASTNode *expr;

public:
    ASTNode_Expr_New_Array_Int(ASTNode *expr)
        : expr(expr)
    {

    }

    void print() override {
        std::cout << "new int [ ";
        expr->print();
        std::cout << " ]";
    }
};

class ASTNode_Expr_New_Array_Bool : public ASTNode {
private:
    ASTNode *expr;

public:
    ASTNode_Expr_New_Array_Bool(ASTNode *expr)
        : expr(expr)
    {

    }

    void print() override {
        std::cout << "new bool [ ";
        expr->print();
        std::cout << " ]";
    }
};

class ASTNode_Expr_New_Array_Void : public ASTNode {
private:
    ASTNode *expr;

public:
    ASTNode_Expr_New_Array_Void(ASTNode *expr)
        : expr(expr)
    {

    }

    void print() override {
        std::cout << "new void [ ";
        expr->print();
        std::cout << " ]";
    }
};

class ASTNode_Expr_New_Array_Custom : public ASTNode {
private:
    ASTNode *expr;
    std::string type;

public:
    ASTNode_Expr_New_Array_Custom(ASTNode *expr, const char *type_c)
        : expr(expr), type(type_c)
    {

    }

    void print() override {
        std::cout << "new " << type << " [ ";
        expr->print();
        std::cout << " ]";
    }
};

class ASTNode_Expr_New_Array_IntArray : public ASTNode {
private:
	ASTNode *expr;

public:
    ASTNode_Expr_New_Array_IntArray(ASTNode *expr)
        : expr(expr)
    {

    }

    void print() override {
        std::cout << "new int [] [ ";
        expr->print();
        std::cout << " ]";
    }
};

class ASTNode_Expr_New_Array_BoolArray : public ASTNode {
private:
    ASTNode *expr;

public:
    ASTNode_Expr_New_Array_BoolArray(ASTNode *expr)
        : expr(expr)
    {

    }

    void print() override {
        std::cout << "new bool [] [ ";
        expr->print();
        std::cout << " ]";
    }
};

class ASTNode_Expr_New_Array_VoidArray : public ASTNode {
private:
    ASTNode *expr;

public:
    ASTNode_Expr_New_Array_VoidArray(ASTNode *expr)
        : expr(expr)
    {

    }

    void print() override {
        std::cout << "new void [] [ ";
        expr->print();
        std::cout << " ]";
    }
};

class ASTNode_Expr_New_Array_CustomArray : public ASTNode {
private:
    ASTNode *expr;
    std::string type;

public:
    ASTNode_Expr_New_Array_CustomArray(ASTNode *expr, const char *type_c)
        : expr(expr), type(type_c)
    {

    }

    void print() override {
        std::cout << "new " << type << "[] [ ";
        expr->print();
        std::cout << " ]";
    }
};

class ASTNode_Statement_ExprOnly : public ASTNode {
private:
    ASTNode *expr;

public:
    ASTNode_Statement_ExprOnly(ASTNode *expr) 
        : expr(expr)
    {

    }

    void print() override {
		expr->print();
        std::cout << ";" << std::endl;
    }
};

class ASTNode_Statement_VariableDeclaration_Int : public ASTNode {
private:
    std::string name;

public:
    ASTNode_Statement_VariableDeclaration_Int(const char* name_c)
        : name(name_c)
    {

    }

    void print() override {
        std::cout << "int " << name << ";" << std::endl;
    }
};

class ASTNode_Statement_VariableDeclaration_Custom : public ASTNode {
private:
    std::string name;
    std::string type;

public:
    ASTNode_Statement_VariableDeclaration_Custom(const char* type_c, const char* name_c)
        : type(type_c), name(name_c)
    {

    }

    void print() override {
        std::cout << type << " " << name << ";" << std::endl;
    }
};

class ASTNode_Statement_VariableDeclaration_Bool : public ASTNode {
private:
    std::string name;

public:
    ASTNode_Statement_VariableDeclaration_Bool(const char* name_c)
        : name(name_c)
    {

    }

    void print() override {
        std::cout << "bool " << name << ";" << std::endl;
    }
};

class ASTNode_Statement_VariableDeclaration_Void : public ASTNode {
private:
    std::string name;

public:
    ASTNode_Statement_VariableDeclaration_Void(const char* name_c)
        : name(name_c)
    {

    }

    void print() override {
        std::cout << "void " << name << ";" << std::endl;
    }
};

class ASTNode_Statement_VariableDeclaration_Int_Array : public ASTNode {
private:
    std::string name;

public:
    ASTNode_Statement_VariableDeclaration_Int_Array(const char* name_c)
        : name(name_c)
    {

    }

    void print() override {
        std::cout << "int[] " << name << ";" << std::endl;
    }
};

class ASTNode_Statement_VariableDeclaration_Custom_Array : public ASTNode {
private:
    std::string name;
    std::string type;

public:
    ASTNode_Statement_VariableDeclaration_Custom_Array(const char* type_c, const char* name_c)
        : type(type_c), name(name_c)
    {

    }

    void print() override {
        std::cout << type << "[] " << name << ";" << std::endl;
    }
};

class ASTNode_Statement_VariableDeclaration_Bool_Array : public ASTNode {
private:
    std::string name;

public:
    ASTNode_Statement_VariableDeclaration_Bool_Array(const char* name_c)
        : name(name_c)
    {

    }

    void print() override {
        std::cout << "bool[] " << name << ";" << std::endl;
    }
};

class ASTNode_Statement_VariableDeclaration_Void_Array : public ASTNode {
private:
    std::string name;

public:
    ASTNode_Statement_VariableDeclaration_Void_Array(const char* name_c)
        : name(name_c)
    {

    }

    void print() override {
        std::cout << "void[] " << name << ";" << std::endl;
    }
};

class ASTNode_Statement_Empty : public ASTNode {
public:
    ASTNode_Statement_Empty() {

    }

    void print() override {
        std::cout << ";" << std::endl;
    }
};

class ASTNode_Statement_Return : public ASTNode {
private:
    ASTNode *expr;

public:
    ASTNode_Statement_Return(ASTNode *expr) 
        : expr(expr)
    {

    }

    void print() override {
        std::cout << "return ";
        expr->print();
        std::cout << ";" << std::endl;
    }
};

class ASTNode_Statement_Body : public ASTNode {
private:
    std::vector<ASTNode*> nodes;

public:
    ASTNode_Statement_Body() {

    }

    void AddStatement(ASTNode *node) {
		nodes.insert(nodes.begin(), node);
    }

    void print() override {
        std::cout << "{" << std::endl;
        for (auto statement : nodes)
            statement->print();
        std::cout << "}" << std::endl;
    }
};

class ASTNode_Statement_While : public ASTNode {
private:
    ASTNode *condition_expr;
    ASTNode *statement;

public:
    ASTNode_Statement_While(ASTNode *condition_expr, ASTNode *statement)
        : condition_expr(condition_expr), statement(statement)
    {

    }

    void print() override {
        std::cout << "while ( ";
		condition_expr->print();
        std::cout << " )" << std::endl;
        statement->print();
    }
};

class ASTNode_Statement_If : public ASTNode {
private:
	ASTNode *condition_expr;
    ASTNode *statement;

public:
    ASTNode_Statement_If(ASTNode *condition_expr, ASTNode *statement) 
        : condition_expr(condition_expr), statement(statement)
    {

    }

    void print() override {
        std::cout << "if ( ";
        condition_expr->print();
        std::cout << ")" << std::endl;
        statement->print();
    }
};

class ASTNode_Statement_IfElse : public ASTNode {
private:
	ASTNode *condition_expr;
    ASTNode *statement_true;
    ASTNode *statement_false;

public:
    ASTNode_Statement_IfElse(ASTNode *condition_expr, ASTNode *statement_true, ASTNode *statement_false) 
        : condition_expr(condition_expr), statement_true(statement_true), statement_false(statement_false)
    {

    }

    void print() override {
        std::cout << "if ( ";
        condition_expr->print();
        std::cout << ")" << std::endl;
        statement_true->print();
        std::cout << "else" << std::endl;
        statement_false->print();
    }
};

class AST {
public:
    std::vector<std::unique_ptr<ASTNode>> nodes;

public:
    template <typename T>
    T* AddNode(std::unique_ptr<T>&& ptr) {
        nodes.push_back(std::move(ptr));
        return (T*)nodes[nodes.size() - 1].get();
    }

    ASTNode* GetRootNode() {
		if (nodes.size() == 0)
            return nullptr;
        return nodes[nodes.size() - 1].get();
    }
};

class Parser {
public:
	AST ast;

    Parser() {
    }
};
