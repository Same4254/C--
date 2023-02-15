#pragma once

#include <iostream>
#include <memory>
#include <ostream>
#include <unordered_map>
#include <vector>

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

public:
    Type(TYPE_ID id, const std::string &name) 
        : id(id), name(name), scope(nullptr), parent_type(nullptr)
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

    virtual bool typeEqual(const std::shared_ptr<Type> other) const = 0;
    virtual bool isSubtype(const std::shared_ptr<Type> other) const = 0;

    const std::string& getName() const { return name; }
    const TYPE_ID getID() const { return id; }
    
    const std::shared_ptr<Scope> getScope() const { return scope; }
    void setScope(std::shared_ptr<Scope> scope) { this->scope = scope; }
};

class Type_Int : public Type {
public:
    Type_Int() 
        : Type(TYPE_ID::INT, "TYPE_INT")
    {

    }

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
private:
    std::shared_ptr<Type> element_type;

public:
    Type_Array(std::shared_ptr<Type> element_type) 
        : Type(TYPE_ID::ARRAY, "TYPE_ARRAY"), element_type(element_type)
    {

    }

    bool typeEqual(const std::shared_ptr<Type> other) const override {
        if (this->id == other->getID())
            return element_type->typeEqual(std::static_pointer_cast<Type_Array>(other)->element_type);
        return false;
    }

    bool isSubtype(const std::shared_ptr<Type> other) const override {
        if (this->id == other->getID())
            return element_type->isSubtype(std::static_pointer_cast<Type_Array>(other)->element_type);
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

    virtual void print(std::ostream &stream) const {
        stream << *this->type << " ";
    }

    friend std::ostream& operator<<(std::ostream &stream, const Descriptor &descriptor) {
        descriptor.print(stream);
        return stream;
    }
};

class Descriptor_Class : public Descriptor {
private:
    //std::shared_ptr<Descriptor_Class> parent_class;

public:
    Descriptor_Class(std::string name)
        : Descriptor(std::make_shared<Type_Class>(name))
    {

    }

    void print(std::ostream &stream) const override;

    //void setParentClass(std::shared_ptr<Descriptor_Class> parent_class) {
    //    this->parent_class = parent_class;
    //    this->type->setParentClassType(parent_class->getType());
    //}
};

class Descriptor_Method : public Descriptor {
private:
    std::vector<std::shared_ptr<Type>> argument_types;

public:
    Descriptor_Method(std::string name, std::shared_ptr<Type> return_type) 
        : Descriptor(return_type) 
    {

    }

    void addArgumentType(std::shared_ptr<Type> type) {
        argument_types.push_back(type);
    }

    void print(std::ostream &stream) const override { 
        stream << *type << ", ( ";
        for (auto t : argument_types)
            stream << *t << " ";
        stream << ")";
    }
};

class Descriptor_Field : public Descriptor {
public:
    Descriptor_Field(std::shared_ptr<Type> type) 
        : Descriptor(type) 
    {

    }
};
