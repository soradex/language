#include <iostream>
#include <string>
#include <vector>
#include <sstream>

int main() {
    using namespace std;

    string input;
    cout << "数式を入力してください (例: 10 + 5 - 2): " << endl;
    getline(cin, input);

    stringstream ss(input);
    int pos = 0;
    string token;
    
    int result = 0;
    int commandcount = 0;
    char lastOp = '+';

    vector<string> inputlist(0);

    for (int i = 0; i < input.length(); ++i) {
        if(input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == ' ' ) {
            cout << "演算子: " << input[i] << endl;
            inputlist.push_back(string(1, input[i]));
            commandcount+=2;
        }else{
            cout << inputlist.size() << ":" << input[i] << endl;
            if(inputlist.size() == commandcount){
                inputlist.push_back("");
            }
            inputlist[commandcount] += input[i];
            for (int j = i+1; j < input.length(); ++j) {
                
                
                if(input[j] == '+' || input[j] == '-' || input[j] == '*' || input[j] == '/' || input[j] == ' ' ) {
                    cout << "break"<< endl;
                    i = j-1;
                    break;
                }else {
                    cout << inputlist.size() << ":" << input[j] <<  ":::" << j << endl;
                    inputlist[commandcount] += input[j];
                }

            }
            
        }
    }
    for(int i = 0; i < inputlist.size(); ++i){
        cout <<  inputlist[i] << "    " ;
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