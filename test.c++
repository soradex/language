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
    
    //　字句解析してリストに区切って入れる
    for (int i = 0; i < input.length(); ++i) {
        if(input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
            cout << "演算子: " << input[i] << endl;
            inputlist.push_back(string(1, input[i]));
            commandcount+=2;
        }else{
            cout << inputlist.size() << ":" << input[i] << endl;
            if(inputlist.size() == commandcount){
                inputlist.push_back("");
            }
            inputlist[commandcount] += input[i];
            for (int j = i+1; j < input.length()+100; ++j) {
                cout << input.length()<< endl;
                if(input.length() ==j){
                    cout << "break"<< j << endl;
                    i = j-1;
                    break;
                }
                if(input[j] == ' ' ){
                        continue;
                    }
                if(input[j] == '+' || input[j] == '-' || input[j] == '*' || input[j] == '/') {
                    cout << "break"<< j << endl;
                    i = j-1;
                    break;
                }else {
                    cout << inputlist.size() << ":" << input[j] <<  ":::" << j << endl;
                    inputlist[commandcount] += input[j];
                }

            }
            
        }
    }
    
    //確認用 終わったら消す
    cout << inputlist[0] << endl;
    for(int i = 0; i < inputlist.size(); ++i){
        cout <<  inputlist[i] << "    " ;
    }
    
    //今の所の計算方法(ここから変えていく)
    for (int i = 0; i < inputlist.size(); ++i) {
        std::string t = inputlist[i];
        if (t == "+") {
            lastOp = '+';
        } else if (t == "-") {
            lastOp = '-';
        } else if (t != "") { // 空白対策
            int num = std::stoi(t);
            if (lastOp == '+') result += num;
            else if (lastOp == '-') result -= num;
        }
    }
    std::cout << "計算結果: " << result << std::endl;

    return 0;
}