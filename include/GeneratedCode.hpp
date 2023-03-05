#pragma once

#include <llvm-14/llvm/IR/Module.h>
#include <memory>

#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Constants.h>

class GeneratedCode {
private:
    llvm::LLVMContext context;
    llvm::IRBuilder<> builder;
    llvm::Module module;

public:
    GeneratedCode() : builder(context), module("The Betterest Compiler!", context) {}

    llvm::Value* getNewLiteral(int value) { return llvm::ConstantInt::get(context, llvm::APInt(32, value)); }

    llvm::LLVMContext& getContext() { return context; }
    llvm::IRBuilder<>& getBuilder() { return builder; }
    llvm::Module& getModule() { return module; }
};
