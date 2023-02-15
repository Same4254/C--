#include "Scoping.hpp"
#include "Type.hpp"

void Type::pushScope(Environment &environment) const {
    if (this->scope != nullptr)
        environment.addScope(this->scope);
}

void Type::popScope(Environment &environment) const {
    if (this->scope != nullptr)
        environment.popScope();
}

void Type_Class::pushScope(Environment &environment) const {
    if (this->parent_type != nullptr)
        parent_type->pushScope(environment);

    environment.addScope(this->scope);
}

void Type_Class::popScope(Environment &environment) const {
    if (this->parent_type != nullptr)
        parent_type->popScope(environment);

    environment.popScope();
}
