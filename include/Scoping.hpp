#pragma once

#include <memory>
#include <optional>
#include <iostream>
#include <vector>
#include <unordered_map>

#include "Type.hpp"

class Scope {
private:
    std::unordered_map<std::string, std::shared_ptr<Descriptor_Method>> method_descriptors;
    std::unordered_map<std::string, std::shared_ptr<Descriptor_Variable>> variable_descriptors;

public:
    typedef std::optional<const std::shared_ptr<Descriptor_Method>> MaybeMethodDescriptor;
    typedef std::optional<const std::shared_ptr<Descriptor_Variable>> MaybeVariableDescriptor;

    MaybeMethodDescriptor getMethodDescriptor(const std::string &id);
    MaybeVariableDescriptor getVariableDescriptor(const std::string &id);

    void setMethodDescriptor(const std::string &id, std::shared_ptr<Descriptor_Method> desc);
    void setVariableDescriptor(const std::string &id, std::shared_ptr<Descriptor_Variable> desc);

    friend std::ostream& operator<<(std::ostream &stream, const Scope &scope) {
        for (auto pair : scope.method_descriptors)
            stream << pair.first << " : { " << *pair.second << "}" << std::endl;

        for (auto pair : scope.variable_descriptors)
            stream << pair.first << " : { " << *pair.second << "}" << std::endl;

        return stream;
    }
};

/**
 * @brief An environment stores the scopes that encompass one another (i.e. a stack of scopes)
 */
class Environment {
private:
    std::unordered_map<std::string, std::shared_ptr<Descriptor_Class>> class_descriptors;
    std::vector<std::shared_ptr<Scope>> scope_stack;

public:
    std::shared_ptr<Descriptor_Class> getClassDescriptor(const std::string &id);
    std::shared_ptr<Descriptor_Method> getMethodDescriptor(const std::string &id);
    std::shared_ptr<Descriptor_Variable> getVariableDescriptor(const std::string &id);

    void setClassDescriptor(const std::string &id, std::shared_ptr<Descriptor_Class> desc);

    bool hasClassDescriptor(const std::string &id);
    bool hasMethodDescriptor(const std::string &id);
    bool hasVariableDescriptor(const std::string &id);

    void pushScope(std::shared_ptr<Scope> scope);
    void popScope();

    /**
     * @brief Get the most recently pushed Scope
     *
     * @return 
     */
    std::shared_ptr<Scope> getTopScope();

    /**
     * @brief Gets the root scope (list of classes for this language)
     *
     * @return 
     */
    std::shared_ptr<Scope> getBottomScope();
};
