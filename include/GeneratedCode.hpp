#pragma once

#include <memory>

#include <llvm/IR/Module.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Constants.h>
#include <llvm/Support/raw_ostream.h>

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
