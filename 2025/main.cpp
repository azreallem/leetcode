#include "functions.h"

int main(int argc, char* argv[]) {
    // 检查命令行参数数量
    if (argc < 2) {
        printHelp();
        return 1;
    }

    // 获取函数名并调用
    std::string functionName = argv[1];
    callRegisteredFunction(functionName);

    return 0;
}

