#include <iostream>
#include <string>
#include <vector>
#include <sstream>

int main() {
    std::string input;
    std::cout << "数式を入力してください (例: 10 + 5 - 2): " << std::endl;
    std::getline(std::cin, input);

    std::stringstream ss(input);
    int pos = 0;
    std::string token;
    
    int result = 0;
    char lastOp = '+'; // 最初は 0 + (最初の数) と考える
    
    for (int i = 0; i < input.length(); ++i) {
        std::cout << "r" << std::endl;
    }

    while (ss >> token) {
        if (token == "+" || token == "-") {
            lastOp = token[0];
        } else {
            // 文字列を数値に変換
            int num = std::stoi(token);
            if (lastOp == '+') result += num;
            else if (lastOp == '-') result -= num;
        }
    }

    std::cout << "計算結果: " << result << std::endl;
    return 0;
}