#pragma once

#include <iostream>
#include <vector>
#include <memory>

class ASTNode {
public:
	virtual ~ASTNode() = default;

    virtual void print() = 0;
};

class ASTNode_Expr : public ASTNode {

};

class ASTNode_Expr_Times : public ASTNode_Expr {
private:
	ASTNode_Expr *left;
	ASTNode_Expr *right;

public:
    ASTNode_Expr_Times(ASTNode_Expr *left, ASTNode_Expr *right)
        : left(left), right(right)
    {

    }

    void print() override {
        left->print();
        std::cout << " * ";
        right->print();
    }
};

class ASTNode_Expr_Divide : public ASTNode_Expr {
private:
	ASTNode_Expr *left;
	ASTNode_Expr *right;

public:
    ASTNode_Expr_Divide(ASTNode_Expr *left, ASTNode_Expr *right)
        : left(left), right(right)
    {

    }

    void print() override {
        left->print();
        std::cout << " / ";
        right->print();
    }
};

class ASTNode_Expr_Plus : public ASTNode_Expr {
private:
	ASTNode_Expr *left;
	ASTNode_Expr *right;

public:
    ASTNode_Expr_Plus(ASTNode_Expr *left, ASTNode_Expr *right)
        : left(left), right(right)
    {

    }

    void print() override {
        left->print();
        std::cout << " + ";
        right->print();
    }
};

class ASTNode_Expr_Minus : public ASTNode_Expr {
private:
	ASTNode_Expr *left;
	ASTNode_Expr *right;

public:
    ASTNode_Expr_Minus(ASTNode_Expr *left, ASTNode_Expr *right)
        : left(left), right(right)
    {

    }

    void print() override {
        left->print();
        std::cout << " - ";
        right->print();
    }
};

class ASTNode_Expr_Parenthesis : public ASTNode_Expr {
private:
	ASTNode_Expr *expr;

public:
    ASTNode_Expr_Parenthesis(ASTNode_Expr *expr)
        : expr(expr)
    {

    }

    void print() override {
        std::cout << "( ";
        expr->print();
        std::cout << " )";
    }
};

class ASTNode_Expr_And : public ASTNode_Expr {
private:
	ASTNode_Expr *left;
	ASTNode_Expr *right;

public:
    ASTNode_Expr_And(ASTNode_Expr *left, ASTNode_Expr *right)
        : left(left), right(right)
    {

    }

    void print() override {
        left->print();
        std::cout << " && ";
        right->print();
    }
};

class ASTNode_Expr_Or : public ASTNode_Expr {
private:
	ASTNode_Expr *left;
	ASTNode_Expr *right;

public:
    ASTNode_Expr_Or(ASTNode_Expr *left, ASTNode_Expr *right)
        : left(left), right(right)
    {

    }

    void print() override {
        left->print();
        std::cout << " || ";
        right->print();
    }
};

class ASTNode_Expr_Equivalent : public ASTNode_Expr {
private:
	ASTNode_Expr *left;
	ASTNode_Expr *right;

public:
    ASTNode_Expr_Equivalent(ASTNode_Expr *left, ASTNode_Expr *right)
        : left(left), right(right)
    {

    }

    void print() override {
        left->print();
        std::cout << " == ";
        right->print();
    }
};

class ASTNode_Expr_IsNotEqual : public ASTNode_Expr {
private:
	ASTNode_Expr *left;
	ASTNode_Expr *right;

public:
    ASTNode_Expr_IsNotEqual(ASTNode_Expr *left, ASTNode_Expr *right)
        : left(left), right(right)
    {

    }

    void print() override {
        left->print();
        std::cout << " != ";
        right->print();
    }
};

class ASTNode_Expr_LessThanOrEqual : public ASTNode_Expr {
private:
	ASTNode_Expr *left;
	ASTNode_Expr *right;

public:
    ASTNode_Expr_LessThanOrEqual(ASTNode_Expr *left, ASTNode_Expr *right)
        : left(left), right(right)
    {

    }

    void print() override {
        left->print();
        std::cout << " <= ";
        right->print();
    }
};

class ASTNode_Expr_LessThan : public ASTNode_Expr {
private:
	ASTNode_Expr *left;
	ASTNode_Expr *right;

public:
    ASTNode_Expr_LessThan(ASTNode_Expr *left, ASTNode_Expr *right)
        : left(left), right(right)
    {

    }

    void print() override {
        left->print();
        std::cout << " < ";
        right->print();
    }
};

class ASTNode_Expr_GreaterThanOrEqual : public ASTNode_Expr {
private:
	ASTNode_Expr *left;
	ASTNode_Expr *right;

public:
    ASTNode_Expr_GreaterThanOrEqual(ASTNode_Expr *left, ASTNode_Expr *right)
        : left(left), right(right)
    {

    }

    void print() override {
        left->print();
        std::cout << " >= ";
        right->print();
    }
};

class ASTNode_Expr_GreaterThan : public ASTNode_Expr {
private:
	ASTNode_Expr *left;
	ASTNode_Expr *right;

public:
    ASTNode_Expr_GreaterThan(ASTNode_Expr *left, ASTNode_Expr *right)
        : left(left), right(right)
    {

    }

    void print() override {
        left->print();
        std::cout << " > ";
        right->print();
    }
};

class ASTNode_Expr_UnaryMinus : public ASTNode_Expr {
private:
	ASTNode_Expr *expr;

public:
    ASTNode_Expr_UnaryMinus(ASTNode_Expr *expr)
        : expr(expr)
    {

    }

    void print() override {
        std::cout << "-";
        expr->print();
    }
};

class ASTNode_Expr_BooleanNegate : public ASTNode_Expr {
private:
	ASTNode_Expr *expr;

public:
    ASTNode_Expr_BooleanNegate(ASTNode_Expr *expr)
        : expr(expr)
    {

    }

    void print() override {
        std::cout << "!";
        expr->print();
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

    void print() override {
        std::cout << integer;
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

    void print() override {
        std::cout << (boolean ? "true" : "false");
    }
};

class ASTNode_Actuals : public ASTNode {
private:
    std::vector<ASTNode_Expr*> expressions;

public:
    ASTNode_Actuals() {
    
    }

    void AddExpression(ASTNode_Expr *expr) {
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

class ASTNode_Expr_New_Obj : public ASTNode_Expr {
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

class ASTNode_Expr_New_Array_Int : public ASTNode_Expr {
private:
	ASTNode_Expr *expr;

public:
    ASTNode_Expr_New_Array_Int(ASTNode_Expr *expr)
        : expr(expr)
    {

    }

    void print() override {
        std::cout << "new int [ ";
        expr->print();
        std::cout << " ]";
    }
};

class ASTNode_Expr_New_Array_Bool : public ASTNode_Expr {
private:
    ASTNode_Expr *expr;

public:
    ASTNode_Expr_New_Array_Bool(ASTNode_Expr *expr)
        : expr(expr)
    {

    }

    void print() override {
        std::cout << "new bool [ ";
        expr->print();
        std::cout << " ]";
    }
};

class ASTNode_Expr_New_Array_Void : public ASTNode_Expr {
private:
    ASTNode_Expr *expr;

public:
    ASTNode_Expr_New_Array_Void(ASTNode_Expr *expr)
        : expr(expr)
    {

    }

    void print() override {
        std::cout << "new void [ ";
        expr->print();
        std::cout << " ]";
    }
};

class ASTNode_Expr_New_Array_Custom : public ASTNode_Expr {
private:
    ASTNode_Expr *expr;
    std::string type;

public:
    ASTNode_Expr_New_Array_Custom(ASTNode_Expr *expr, const char *type_c)
        : expr(expr), type(type_c)
    {

    }

    void print() override {
        std::cout << "new " << type << " [ ";
        expr->print();
        std::cout << " ]";
    }
};

class ASTNode_Expr_New_Array_IntArray : public ASTNode_Expr {
private:
	ASTNode_Expr *expr;

public:
    ASTNode_Expr_New_Array_IntArray(ASTNode_Expr *expr)
        : expr(expr)
    {

    }

    void print() override {
        std::cout << "new int [] [ ";
        expr->print();
        std::cout << " ]";
    }
};

class ASTNode_Expr_New_Array_BoolArray : public ASTNode_Expr {
private:
    ASTNode_Expr *expr;

public:
    ASTNode_Expr_New_Array_BoolArray(ASTNode_Expr *expr)
        : expr(expr)
    {

    }

    void print() override {
        std::cout << "new bool [] [ ";
        expr->print();
        std::cout << " ]";
    }
};

class ASTNode_Expr_New_Array_VoidArray : public ASTNode_Expr {
private:
    ASTNode_Expr *expr;

public:
    ASTNode_Expr_New_Array_VoidArray(ASTNode_Expr *expr)
        : expr(expr)
    {

    }

    void print() override {
        std::cout << "new void [] [ ";
        expr->print();
        std::cout << " ]";
    }
};

class ASTNode_Expr_New_Array_CustomArray : public ASTNode_Expr {
private:
    ASTNode_Expr *expr;
    std::string type;

public:
    ASTNode_Expr_New_Array_CustomArray(ASTNode_Expr *expr, const char *type_c)
        : expr(expr), type(type_c)
    {

    }

    void print() override {
        std::cout << "new " << type << "[] [ ";
        expr->print();
        std::cout << " ]";
    }
};

class ASTNode_Statement : public ASTNode {

};

class ASTNode_Statement_ExprOnly : public ASTNode_Statement {
private:
    ASTNode_Expr *expr;

public:
    ASTNode_Statement_ExprOnly(ASTNode_Expr *expr) 
        : expr(expr)
    {

    }

    void print() override {
		expr->print();
        std::cout << ";" << std::endl;
    }
};

class ASTNode_Statement_VariableDeclaration_Int : public ASTNode_Statement {
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

class ASTNode_Statement_VariableDeclaration_Custom : public ASTNode_Statement {
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

class ASTNode_Statement_VariableDeclaration_Bool : public ASTNode_Statement {
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

class ASTNode_Statement_VariableDeclaration_Void : public ASTNode_Statement {
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

class ASTNode_Statement_VariableDeclaration_Int_Array : public ASTNode_Statement {
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

class ASTNode_Statement_VariableDeclaration_Custom_Array : public ASTNode_Statement {
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

class ASTNode_Statement_VariableDeclaration_Bool_Array : public ASTNode_Statement {
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

class ASTNode_Statement_VariableDeclaration_Void_Array : public ASTNode_Statement {
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

class ASTNode_Statement_Empty : public ASTNode_Statement {
public:
    ASTNode_Statement_Empty() {

    }

    void print() override {
        std::cout << ";" << std::endl;
    }
};

class ASTNode_Statement_Return : public ASTNode_Statement {
private:
    ASTNode_Expr *expr;

public:
    ASTNode_Statement_Return(ASTNode_Expr *expr) 
        : expr(expr)
    {

    }

    void print() override {
        std::cout << "return ";
        expr->print();
        std::cout << ";" << std::endl;
    }
};

class ASTNode_Statement_Body : public ASTNode_Statement {
private:
    std::vector<ASTNode_Statement*> nodes;

public:
    ASTNode_Statement_Body() {

    }

    void AddStatement(ASTNode_Statement *statement) {
        // bottom up parsing...
		nodes.insert(nodes.begin(), statement);
    }

    void print() override {
        std::cout << "{" << std::endl;
        for (auto statement : nodes)
            statement->print();
        std::cout << "}" << std::endl;
    }
};

class ASTNode_Statement_While : public ASTNode_Statement {
private:
    ASTNode_Expr *condition_expr;
    ASTNode_Statement *statement;

public:
    ASTNode_Statement_While(ASTNode_Expr *condition_expr, ASTNode_Statement *statement)
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

class ASTNode_Statement_If : public ASTNode_Statement {
private:
	ASTNode_Expr *condition_expr;
    ASTNode_Statement *statement;

public:
    ASTNode_Statement_If(ASTNode_Expr *condition_expr, ASTNode_Statement *statement) 
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

class ASTNode_Statement_IfElse : public ASTNode_Statement {
private:
	ASTNode_Expr *condition_expr;
    ASTNode_Statement *statement_true;
    ASTNode_Statement *statement_false;

public:
    ASTNode_Statement_IfElse(ASTNode_Expr *condition_expr, ASTNode_Statement *statement_true, ASTNode_Statement *statement_false) 
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
    // ownership lives here in this list so that the unique_ptrs do not need to be passed around inside the grammar
    // makes the cleanup process very easy
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
