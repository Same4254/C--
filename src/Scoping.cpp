#include "Scoping.hpp"
#include "Type.hpp"
#include <memory>

Scope::MaybeMethodDescriptor Scope::getMethodDescriptor(const std::string &id) {
    auto search = this->method_descriptors.find(id);
    if (search != this->method_descriptors.end())
        return search->second;
    return {};
}

Scope::MaybeVariableDescriptor Scope::getVariableDescriptor(const std::string &id) {
    auto search = this->variable_descriptors.find(id);
    if (search != this->variable_descriptors.end())
        return search->second;
    return {};
}

void Scope::setMethodDescriptor(const std::string &id, std::shared_ptr<Descriptor_Method> desc) {
    if (variable_descriptors.find(id) != variable_descriptors.end()) {
        std::cout << "[Error]: Method " << id << " already exists in the scope!" << std::endl; 
        exit(1);
    }

    this->method_descriptors.insert(std::make_pair(id, desc));
}

void Scope::setVariableDescriptor(const std::string &id, std::shared_ptr<Descriptor_Variable> desc) {
    if (variable_descriptors.find(id) != variable_descriptors.end()) {
        std::cout << "[Error]: Variable " << id << " already exists in the scope!" << std::endl; 
        exit(1);
    }

    this->variable_descriptors.insert(std::make_pair(id, desc));
}

std::shared_ptr<Descriptor_Class> Environment::getClassDescriptor(const std::string &id) {
    auto search = class_descriptors.find(id);
    if (search == class_descriptors.end()) {
        std::cout << "[Error]: Class named " << id << " does not exist!" << std::endl;
        exit(1);
    }

    return search->second;
}

void Environment::setClassDescriptor(const std::string &id, std::shared_ptr<Descriptor_Class> desc) {
    if (class_descriptors.find(id) != class_descriptors.end()) {
        std::cout << "[Error]: Class " << id << " already exists in the scope!" << std::endl; 
        exit(1);
    }

    this->class_descriptors.insert(std::make_pair(id, desc));
}

bool Environment::hasClassDescriptor(const std::string &id) {
    return class_descriptors.find(id) != class_descriptors.end();
}

std::shared_ptr<Descriptor_Method> Environment::getMethodDescriptor(const std::string &id) {
    for (auto it = scope_stack.rbegin(); it != scope_stack.rend(); it++) {
        auto desc = (*it)->getMethodDescriptor(id);
        if (desc.has_value())
            return desc.value();
    }

    std::cout << "[Error]: Method named " << id << " does not exist!" << std::endl;
    exit(1);
}

bool Environment::hasMethodDescriptor(const std::string &id) {
    for (auto it = scope_stack.rbegin(); it != scope_stack.rend(); it++) {
        auto desc = (*it)->getMethodDescriptor(id);
        if (desc.has_value())
            return true;
    }

    return false;
}

std::shared_ptr<Descriptor_Variable> Environment::getVariableDescriptor(const std::string &id) {
    for (auto it = scope_stack.rbegin(); it != scope_stack.rend(); it++) {
        auto desc = (*it)->getVariableDescriptor(id);
        if (desc.has_value())
            return desc.value();
    }

    std::cout << "[Error]: Variable named " << id << " does not exist!" << std::endl;
    exit(1);
}

bool Environment::hasVariableDescriptor(const std::string &id) {
    for (auto it = scope_stack.rbegin(); it != scope_stack.rend(); it++) {
        auto desc = (*it)->getVariableDescriptor(id);
        if (desc.has_value())
            return true;
    }

    return false;
}

// could use unique pointers here instead?
void Environment::pushScope(std::shared_ptr<Scope> scope) {
    scope_stack.push_back(scope);
}

void Environment::popScope() {
    scope_stack.pop_back();
}

std::shared_ptr<Scope> Environment::getTopScope() {
    return scope_stack[scope_stack.size() - 1];
}

std::shared_ptr<Scope> Environment::getBottomScope() {
    return scope_stack[0];
}
