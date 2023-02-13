#pragma once

#include <string>

enum TYPE_ID {
    INT,
    BOOL,
    VOID,
    CLASS,

    INT_ARRAY,
    BOOL_ARRAY,
    VOID_ARRAY,
    CLASS_ARRAY
};

class Type {
public:
    const TYPE_ID id;
    Type(TYPE_ID id) 
        : id(id) 
    {

    }

    virtual ~Type() = default;

    virtual bool typeEqual(const Type &other) = 0;
};

class Type_Int : public Type {
public:
    Type_Int() 
        : Type(TYPE_ID::INT)
    {

    }

    bool typeEqual(const Type &other) {
        return this->id == other.id;
    }
};

class Type_Bool : public Type {
public:
    Type_Bool() 
        : Type(TYPE_ID::BOOL)
    {

    }

    bool typeEqual(const Type &other) {
        return this->id == other.id;
    }
};

class Type_Void : public Type {
public:
    Type_Void() 
        : Type(TYPE_ID::VOID)
    {

    }

    bool typeEqual(const Type &other) {
        return this->id == other.id;
    }
};

class Type_ID : public Type {
public:
    Type_ID()
        : Type(TYPE_ID::CLASS)
    {

    }

    bool typeEqual(const Type &other) {
        return false;
    }
};

class Descriptor {

};

class Descriptor_Class : public Descriptor {
private:
    std::string name;
    std::string parent_name;

    Descriptor_Class(std::string name) {

    }

    void setParentClass(std::string parent_name) {
        this->parent_name = parent_name;
    }
};
