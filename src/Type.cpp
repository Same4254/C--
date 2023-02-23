#include "Scoping.hpp"
#include "Type.hpp"
#include <ostream>

void Type::pushScope(Environment &environment) const {
    if (this->scope != nullptr)
        environment.pushScope(this->scope);
}

void Type::popScope(Environment &environment) const {
    if (this->scope != nullptr)
        environment.popScope();
}

void Type_Class::pushScope(Environment &environment) const {
    if (this->parent_type != nullptr)
        parent_type->pushScope(environment);

    environment.pushScope(this->scope);
}

void Type_Class::popScope(Environment &environment) const {
    if (this->parent_type != nullptr)
        parent_type->popScope(environment);

    environment.popScope();
}

void Descriptor_Class::print(std::ostream &stream) const {
    stream << "Class " << *type << " {" << std::endl;
    stream << *type->getScope();
    stream << "}";
}
