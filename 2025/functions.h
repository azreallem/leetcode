#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>

// 函数类型
using FunctionPtr = void(*)();

// 宏定义：注册函数到全局映射表
#define REGISTER_FUNCTION(name) \
    void name(); \
    __attribute__((constructor)) void register_##name() { \
        FunctionRegistry::getInstance().registerFunction(#name, name); \
    } \
    void name()

// 函数注册表单例类
class FunctionRegistry {
private:
    std::unordered_map<std::string, FunctionPtr> functions;

    // 私有构造函数（单例模式）
    FunctionRegistry() = default;

public:
    // 获取单例实例
    static FunctionRegistry& getInstance() {
        static FunctionRegistry instance;
        return instance;
    }

    // 注册函数
    void registerFunction(const std::string& name, FunctionPtr func);

    // 调用函数
    void callFunction(const std::string& name);

    // 获取所有可用函数名（用于帮助信息）
    std::vector<std::string> getAvailableFunctions() const;
};

// 全局访问函数注册表的接口
void callRegisteredFunction(const std::string& name);

// 打印帮助信息
void printHelp();

// 打印容器内容
template <typename T>
void print_it(const T it)
{
	for (auto i: it)
		std::cout << i << " ";
	std::cout << std::endl;
}

template <typename T>
void print_2it(const T it)
{
	for (auto it_1 : it) {
		for (auto i : it_1)
			std::cout << i << " ";
		std::cout << std::endl;
	}
}

template <typename T>
void print_map(const T myMap)
{
	for (auto it = myMap.begin(); it != myMap.end(); it++) {
		std::cout << it->first << " : " << it->second << std::endl;
	}
}
#endif // FUNCTIONS_H

