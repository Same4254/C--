#pragma once

#include <memory>
#include <optional>
#include <vector>
#include <unordered_map>

#include "Type.hpp"

class Scope {
private:
    std::unordered_map<std::string, std::shared_ptr<Descriptor>> descriptors;

public:
    typedef std::optional<const std::shared_ptr<Descriptor>> MaybeDescriptor;

    MaybeDescriptor getDescriptor(const std::string &id);
    void setDescriptor(const std::string &id, std::shared_ptr<Descriptor> desc);
};

/**
 * @brief An environment stores the scopes that encompass one another (i.e. a stack of scopes)
 */
class Environment {
private:
    std::vector<std::shared_ptr<Scope>> scope_stack;

public:
    Scope::MaybeDescriptor getDescriptor(const std::string &id);

    void addScope(std::shared_ptr<Scope> scope);
    void popScope();
    std::shared_ptr<Scope> getTopScope();
};
