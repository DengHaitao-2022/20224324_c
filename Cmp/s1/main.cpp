#include "s1.h"
#include <iostream>
#include <filesystem> // C++17
using namespace std;

int main() {
    filesystem::current_path("J:/20224324_c++/Cmp/s1"); //设置当前工作目录
    //打印当前工作目录
    cout << "当前工作目录: " << filesystem::current_path() << endl;
    // 打印提示信息,每种标识符对应的类型
    cout << "1:关键字 2:标识符 3:常量 4:运算符 5:界符 6:头文件" << endl;
    cout << "----------------------------------------" << endl;
    //输入文件名
    string filename;
    cout << "请输入文件名: ";
    cin >> filename;
    Lexer lexer(filename);

    pair<int, string> token; // 存储当前识别的单词符号
    do {
        token = lexer.getNextToken();
        if (token.first == -2) {
            printf("\n");
            cout << "----------------------------------------" << endl;
        } else {
            cout << "("<< token.first << ", \"" << token.second << "\") ";
        }
    } while (token.first != -1); // -1 表示EOF
    return 0;
}