#pragma once

#include <iostream>
#include <memory>
#include <ostream>
#include <unordered_map>
#include <vector>

#include "GeneratedCode.hpp"

// maybe someone should update their parser to have more than two passes so we don't gotta do this :)
class Scope;
class Environment;

enum TYPE_ID {
    INT,
    BOOL,
    VOID,
    CLASS,
    ARRAY
};

class Type {
protected:
    const TYPE_ID id;
    const std::string name;
    std::shared_ptr<Scope> scope;
    std::shared_ptr<Type> parent_type;
    std::shared_ptr<Type> composite_type;

    llvm::Type* llvm_type;

public:
    Type(TYPE_ID id, const std::string &name) 
        : id(id), name(name), scope(nullptr), parent_type(nullptr), composite_type(nullptr), llvm_type(nullptr)
    {

    }

    Type(TYPE_ID id, const std::string &name, std::shared_ptr<Type> composite_type) 
        : id(id), name(name), scope(nullptr), parent_type(nullptr), composite_type(composite_type), llvm_type(nullptr)
    {

    }

    virtual ~Type() = default;

    friend std::ostream& operator<<(std::ostream& stream, const Type &type) {
        stream << "{" << type.name;
        if (type.parent_type != nullptr)
            stream << " Parent: " <<  *type.parent_type;
        stream << "}";
        return stream;
    }

    virtual void pushScope(Environment &environment) const;
    virtual void popScope(Environment &environment) const;

    const std::shared_ptr<Type> getParentClassType() { return parent_type; }
    void setParentClassType(std::shared_ptr<Type> parent_type) { this->parent_type = parent_type; }

    virtual llvm::Type* getLLVMType(GeneratedCode &code) = 0;

    virtual bool typeEqual(const std::shared_ptr<Type> other) const = 0;
    virtual bool isSubtype(const std::shared_ptr<Type> other) const = 0;

    const std::string& getName() const { return name; }
    const TYPE_ID getID() const { return id; }
    
    const std::shared_ptr<Scope> getScope() const { return scope; }
    void setScope(std::shared_ptr<Scope> scope) { this->scope = scope; }

    void setCompositeType(std::shared_ptr<Type> type) {
        if (id != TYPE_ID::ARRAY) {
            std::cout << "[Error]: Cannot set composite type of type " << name << std::endl;
            exit(1);
        }

        if (composite_type != nullptr) {
            std::cout << "[Error]: Array already has composite type" << std::endl;
            exit(1);
        }

        composite_type = type;
    }

    std::shared_ptr<Type> getCompositeType() {
        if (id != TYPE_ID::ARRAY) {
            std::cout << "[Error]: Cannot access the composite type of type " << name << std::endl;
            exit(1);
        }

        if (composite_type == nullptr) {
            std::cout << "[Error]: Array does not have a composite type..." << std::endl;
            exit(1);
        }

        return composite_type;
    }
};

class Type_Int : public Type {
public:
    Type_Int() 
        : Type(TYPE_ID::INT, "TYPE_INT")
    {

    }

    llvm::Type* getLLVMType(GeneratedCode &code) override { return llvm::Type::getInt32Ty(code.getContext()); }

    bool typeEqual(const std::shared_ptr<Type> other) const override {
        return this->id == other->getID();
    }

    bool isSubtype(const std::shared_ptr<Type> other) const override {
        return this->id == other->getID();
    }
};

class Type_Bool : public Type {
public:
    Type_Bool() 
        : Type(TYPE_ID::BOOL, "TYPE_BOOL")
    {

    }

    llvm::Type* getLLVMType(GeneratedCode &code) override { return llvm::Type::getInt32Ty(code.getContext()); }

    bool typeEqual(const std::shared_ptr<Type> other) const override {
        return this->id == other->getID();
    }

    bool isSubtype(const std::shared_ptr<Type> other) const override {
        return this->id == other->getID();
    }
};

class Type_Void : public Type {
public:
    Type_Void() 
        : Type(TYPE_ID::VOID, "TYPE_VOID")
    {

    }

    llvm::Type* getLLVMType(GeneratedCode &code) override { return llvm::Type::getVoidTy(code.getContext()); }

    bool typeEqual(const std::shared_ptr<Type> other) const override {
        return this->id == other->getID();
    }

    bool isSubtype(const std::shared_ptr<Type> other) const override {
        return this->id == other->getID();
    }
};

class Type_Class : public Type {
public:
    Type_Class(std::string &name)
        : Type(TYPE_ID::CLASS, "TYPE_" + name)
    {

    }

    void pushScope(Environment &environment) const override;
    void popScope(Environment &environment) const override;

    llvm::Type* getLLVMType(GeneratedCode &code) override {
        if (this->llvm_type == nullptr)
            this->llvm_type = llvm::StructType::create(code.getContext(), name);
        return llvm_type;
    }

    bool typeEqual(const std::shared_ptr<Type> other) const override {
        return this->id == other->getID() && this == other.get();
    }

    bool isSubtype(const std::shared_ptr<Type> other) const override {
        if (other->getID() != this->id)
            return false;

        if (this->typeEqual(other))
            return true;

        if (this->parent_type != nullptr)
            return this->parent_type->isSubtype(other);

        return false;
    }
};

class Type_Array : public Type {
public:
    Type_Array(std::shared_ptr<Type> element_type) 
        : Type(TYPE_ID::ARRAY, "TYPE_ARRAY", element_type)
    {

    }

    llvm::Type* getLLVMType(GeneratedCode &code) override {
        std::cout << "Array llvm type not implemented!" << std::endl;
        exit(1);
    }

    bool typeEqual(const std::shared_ptr<Type> other) const override {
        if (this->id == other->getID())
            return composite_type->typeEqual(other->getCompositeType());
        return false;
    }

    bool isSubtype(const std::shared_ptr<Type> other) const override {
        if (this->id == other->getID())
            return composite_type->isSubtype(other->getCompositeType());
        return false;
    }
};

class Descriptor {
public:

    virtual void print(std::ostream &stream) const = 0;
    //virtual void print(std::ostream &stream) const {
    //    stream << *this->type << " ";
    //}

    friend std::ostream& operator<<(std::ostream &stream, const Descriptor &descriptor) {
        descriptor.print(stream);
        return stream;
    }
};

class Descriptor_Variable : public Descriptor {
protected: 
    std::string name;
    std::shared_ptr<Type> type;
    llvm::Value *location;

public:
    Descriptor_Variable(std::string name, std::shared_ptr<Type> type)
        : name(name), type(type)
    {

    }

    std::shared_ptr<Type> getType() const { return type; }

    void setLLVMValue(llvm::Value* location) { this->location = location; }
    llvm::Value* getLLVMValue() { return this->location; }

    std::string getName() { return name; }

    virtual void print(std::ostream &stream) const override {
        stream << *this->type << " ";
    }
};

class Descriptor_Method : public Descriptor {
private:
    std::shared_ptr<Type> return_type;
    std::string name;

    std::vector<std::shared_ptr<Descriptor_Variable>> local_variable_descriptors;
    std::vector<std::shared_ptr<Descriptor_Variable>> argument_descriptors;

    bool hasReturn;

public:
    Descriptor_Method(std::string name, std::shared_ptr<Type> return_type) 
        : return_type(return_type), name(name), hasReturn(false)
    {

    }

    std::string getName() { return name; }

    std::shared_ptr<Type> getReturnType() { return return_type; }

    void setHasReturnStmt(bool hasReturn) { this->hasReturn = hasReturn; }
    bool hasReturnStmt() { return hasReturn; }

    const std::vector<std::shared_ptr<Descriptor_Variable>>& getArgumentDescriptors() { return argument_descriptors; }
    void addArgumentDescriptor(std::shared_ptr<Descriptor_Variable> argument_desc) {
        argument_descriptors.push_back(argument_desc);
    }

    const std::vector<std::shared_ptr<Descriptor_Variable>>& getLocalVariableDescriptors() { return local_variable_descriptors; }
    void addLocalVariable(std::shared_ptr<Descriptor_Variable> local_variable) {
        local_variable_descriptors.push_back(local_variable);
    }

    void print(std::ostream &stream) const override { 
        stream << *return_type << ", ( ";
        for (auto t : argument_descriptors)
            stream << *t << " ";
        stream << ")";
    }
};



class Descriptor_Constructor : public Descriptor_Method {
private:
    std::vector<std::shared_ptr<Type>> argument_types;

public:
    Descriptor_Constructor(std::string name) 
        : Descriptor_Method(name, std::make_shared<Type_Void>()) 
    {

    }

    void addArgumentType(std::shared_ptr<Type> type) {
        argument_types.push_back(type);
    }

    void print(std::ostream &stream) const override { 
        stream << "( ";
        for (auto t : argument_types)
            stream << *t << " ";
        stream << ")";
    }
};

class Descriptor_Class : public Descriptor {
private:
    std::shared_ptr<Descriptor_Class> parent_class;
    std::shared_ptr<Type> type;

    std::shared_ptr<Descriptor_Constructor> desc_constructor;

    std::vector<std::shared_ptr<Descriptor_Variable>> desc_fields;
    std::vector<llvm::Type*> field_types;

    std::vector<std::shared_ptr<Descriptor_Method>> desc_methods;

    std::string name;

public:
    Descriptor_Class(std::string name)
        : type(std::make_shared<Type_Class>(name)), desc_constructor(nullptr), name(name)
    {

    }

    void genCode(GeneratedCode &code) {
        for (auto desc_field : desc_fields)
            field_types.push_back(desc_field->getType()->getLLVMType(code));

        ((llvm::StructType*) type->getLLVMType(code))->setBody(field_types);
    }

    void print(std::ostream &stream) const override;
    
    std::shared_ptr<Type> getType() { return type; }

    void setParentClass(std::shared_ptr<Descriptor_Class> parent_class) {
        if (this->parent_class != nullptr) {
            std::cout << "[Error]: Class " << name << " already has parent Class " << this->parent_class->name << ". Cannot set the parent to " << parent_class->name << std::endl;
            exit(1);
        }

        this->parent_class = parent_class;
        this->type->setParentClassType(parent_class->type);
    }

    void setConstructor(std::shared_ptr<Descriptor_Constructor> desc_constructor) {
        if (hasConstructor()) {
            std::cout << "Cannot have multiple definitions of the constructor for class " << type->getName() << std::endl;
            exit(1);
        }

        if (desc_constructor->getName() == this->name) {
            this->desc_constructor = desc_constructor;
        } else {
            std::cout << "[Error]: Class name " << this->name << " and constructor name " << desc_constructor->getName() << " do not match!" << std::endl;
            exit(1);
        }
    }

    bool hasConstructor() { return desc_constructor != nullptr; }

    void addField(std::shared_ptr<Descriptor_Variable> desc_field) {
        desc_fields.push_back(desc_field);
    }

    void addMethod(std::shared_ptr<Descriptor_Method> desc_method) {
        desc_methods.push_back(desc_method);
    }
};


