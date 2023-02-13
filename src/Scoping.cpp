#include "Scoping.hpp"

Scope::MaybeDescriptor Scope::getDescriptor(const std::string &id) {
    auto search = this->descriptors.find(id);
    if (search != this->descriptors.end())
        return search->second;
    return {};
}

Scope::MaybeDescriptor Environment::getDescriptor(const std::string &id) {
    for (auto it = scope_stack.rbegin(); it != scope_stack.rend(); it++) {
        auto desc = (*it)->getDescriptor(id);
        if (desc.has_value())
            return desc;
    }

    return {};
}

// could use unique pointers here instead?
void Environment::addScope(std::shared_ptr<Scope> scope) {
    scope_stack.push_back(scope);
}

void Environment::popScope() {
    scope_stack.pop_back();
}

std::shared_ptr<Scope> Environment::getTopScope() {
    return scope_stack[scope_stack.size() - 1];
}
