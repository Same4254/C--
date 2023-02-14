#pragma once

#include <string>
#include <memory>

// maybe someone should update their parser to have more than two passes so we don't gotta do this :)
class Scope;
class Environment;

enum TYPE_ID {
    INT,
    BOOL,
    VOID,
    CLASS,
};

class Type {
protected:
    const TYPE_ID id;
    const std::string name;
    std::shared_ptr<Scope> scope;
    std::shared_ptr<Type> parent_type;

public:
    Type(TYPE_ID id, const std::string &name) 
        : id(id), name(name), scope(nullptr), parent_type(nullptr)
    {

    }

    virtual ~Type() = default;

    virtual void pushScope(Environment &environment) const;

    const std::shared_ptr<Type> getParentClassType() { return parent_type; }
    void setParentClassType(std::shared_ptr<Type> parent_type) { this->parent_type = parent_type; }

    virtual bool typeEqual(const Type &other) const = 0;
    virtual bool isSubtype(const Type &other) const = 0;

    const std::string& getName() const { return name; }
    const TYPE_ID getID() const { return id; }
    
    const std::shared_ptr<Scope> getScope() const { return scope; }
    void setScope(std::shared_ptr<Scope> scope) { this->scope = scope; }
};

class Type_Int : public Type {
public:
    Type_Int() 
        : Type(TYPE_ID::INT, "int")
    {

    }

    bool typeEqual(const Type &other) {
        return this->id == other.getID();
    }

    bool isSubtype(const Type &other) {
        return this->id == other.getID();
    }
};

class Type_Bool : public Type {
public:
    Type_Bool() 
        : Type(TYPE_ID::BOOL, "bool")
    {

    }

    bool typeEqual(const Type &other) {
        return this->id == other.getID();
    }

    bool isSubtype(const Type &other) {
        return this->id == other.getID();
    }
};

class Type_Void : public Type {
public:
    Type_Void() 
        : Type(TYPE_ID::VOID, "void")
    {

    }

    bool typeEqual(const Type &other) {
        return this->id == other.getID();
    }

    bool isSubtype(const Type &other) {
        return this->id == other.getID();
    }
};

class Type_Class : public Type {
public:
    Type_Class(std::string &name)
        : Type(TYPE_ID::CLASS, name)
    {

    }

    void pushScope(Environment &environment) const override;

    bool typeEqual(const Type &other) const override {
        return this->id == other.getID() && this->name == other.getName();
    }

    bool isSubtype(const Type &other) const override {
        if (other.getID() != this->id)
            return false;

        if (this->typeEqual(other))
            return true;

        if (this->parent_type != nullptr)
            return this->parent_type->isSubtype(other);

        return false;
    }
};

class Descriptor {
protected:
    std::shared_ptr<Type> type;

public:
    Descriptor(std::shared_ptr<Type> type)
        : type(type)
    {

    }

    const std::shared_ptr<Type> getType() const { return type; }
};

class Descriptor_Class : public Descriptor {
private:
    std::shared_ptr<Descriptor_Class> parent_class;

public:
    Descriptor_Class(std::string name)
        : Descriptor(std::make_shared<Type_Class>(name))
    {

    }

    void setParentClass(std::shared_ptr<Descriptor_Class> parent_class) {
        this->parent_class = parent_class;
        this->type->setParentClassType(parent_class->getType());
    }
};
