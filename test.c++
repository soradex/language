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
    int commandcount = 0;
    char lastOp = '+';

    std::vector<std::string> vec(0);

    for (int i = 0; i < input.length(); ++i) {
        if(input[i] == '+' || input[i] == '-') {
            std::cout << "演算子: " << input[i] << std::endl;
            vec.push_back(std::string(1, input[i]));
            commandcount+=2;
        }else{
            std::cout << vec.size() << ":" << input[i] << std::endl;
            if(vec.size() == commandcount){
                vec.push_back("");
            }
            vec[commandcount] += input[i];
            
        }
    }
    for(int i = 0; i < vec.size(); ++i){
        std::cout <<  vec[i] << "    " ;
    }
    /*
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
    */
    //std::cout << "計算結果: " << result << std::endl;
    return 0;
}