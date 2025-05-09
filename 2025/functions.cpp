#include <iostream>
#include <string>
#include "functions.h"

void FunctionRegistry::registerFunction(const std::string& name, FunctionPtr func) {
    functions[name] = func;
}

void FunctionRegistry::callFunction(const std::string& name) {
    auto it = functions.find(name);
    if (it != functions.end()) {
        it->second();  // 调用函数
    } else {
        std::cerr << "Error: Unknown function '" << name << "'" << std::endl;
    }
}

std::vector<std::string> FunctionRegistry::getAvailableFunctions() const {
    std::vector<std::string> names;
    for (const auto& pair : functions) {
        names.push_back(pair.first);
    }
    return names;
}

// 全局访问函数注册表的接口
void callRegisteredFunction(const std::string& name) {
    FunctionRegistry::getInstance().callFunction(name);
}

// 打印帮助信息
void printHelp() {
    std::cerr << "Usage: " << "array" << " <function_name>" << std::endl;
    std::cerr << "Available functions:" << std::endl;

    auto& registry = FunctionRegistry::getInstance();
    for (const auto& name : registry.getAvailableFunctions()) {
        std::cerr << "  " << name << std::endl;
    }
}

