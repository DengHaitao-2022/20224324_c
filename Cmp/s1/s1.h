#ifndef S1_H
#define S1_H

#include <string>
#include <utility>

class Lexer {
public:
    Lexer(const std::string& filename);
    std::pair<int, std::string> getNextToken();

private:
    void readChar(); // 读取下一个字符
    void resetToken();  // 重置当前识别的单词符号
    void unreadChar(); // 新增回退字符函数

    std::string prog; // 存储源程序的字符串
    std::string token; // 存储当前识别的单词符号
    char ch; // 当前读取的字符
    int syn; // 当前识别的单词种别, 1:关键字 2:标识符 3:数字 4:运算符 5:界符
    int p; // 源程序字符串的当前读取位置
    int m; // 当前识别的单词符号的长度
    int n; // 用于循环计数的临时变量
    int row; // 当前处理的行号
    int sum; // 用于存储数字的临时变量
    const char* rwtab[8] = { "if","int","for","while","do","return","break","continue" }; // 关键字表
    const char* rwtab1[8] = { "main","a","b","c","d","e","f","g" }; // 标识符表
};

#endif // S1_H