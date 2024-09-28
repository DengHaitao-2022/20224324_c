#include "s1.h"
#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>

// 构造函数，从文件中读取源程序
Lexer::Lexer(const std::string& filename) : p(0), m(0), n(0), row(1), sum(0) {
    std::ifstream file;
    std::string fname = filename;

    // 循环直到成功打开文件
    while (true) {
        file.open(fname);
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                prog += line + '\n';
            }
            file.close();
            break; // 成功打开文件，退出循环
        } else {
            std::cerr << "找不到文件: " << fname << std::endl;
            std::cout << "请重新输入文件名: ";
            std::cin >> fname;
        }
    }
}

// 读取下一个字符
void Lexer::readChar() {
    if (p < prog.size()) {
        ch = prog[p++];
    } else {
        ch = '\0'; // 文件结束
    }
}

// 回退一个字符
void Lexer::unreadChar() {
    if (p > 0) {
        p--;
    }
}

// 重置当前识别的单词符号
void Lexer::resetToken() {
    token.clear();
}

// 获取下一个单词符号
std::pair<int, std::string> Lexer::getNextToken() {
    resetToken();
    readChar();
    while (isspace(ch) && ch != '\n') { // 跳过空白字符
        readChar();
    }
    if (ch == '\n') {
        syn = -2; // 换行符
        row++;
        return {syn, "\\n"};
    }
    if (ch == '\0') {
        syn = -1; // 文件结束
        return {syn, "EOF"};
    }

    if (isalpha(ch)) {
        m = 0;
        while (isalnum(ch)) {  // 读取字母数字串
            token += ch;
            readChar();
        }
        unreadChar(); // 回退一个字符
        syn = 2; // 默认是标识符
        for (n = 0; n < 8; n++) {
            if (token == rwtab[n]) {
                syn = 1; // 关键字
                break;
            }
        }
        for (n = 0; n < 8; n++) {
            if (token == rwtab1[n]) {
                syn = 2; // 标识符
                break;
            }
        }
    } else if (isdigit(ch)) {
        bool isFloat = false;
        token += ch;
        readChar();
        while (isdigit(ch) || ch == '.' || ch == 'e' || ch == 'E') {
            if (ch == '.') {
                if (isFloat) {
                    break; // 如果已经是浮点数，再次遇到小数点则停止
                }
                isFloat = true;
            }
            if (ch == 'e' || ch == 'E') {
                token += ch;
                readChar();
                if (ch == '+' || ch == '-') {
                    token += ch;
                    readChar();
                }
                while (isdigit(ch)) { // 读取指数部分
                    token += ch;
                    readChar();
                }
                break;
            }
            token += ch;
            readChar();
        }
        unreadChar(); // 回退一个字符
        syn = isFloat ? 3 : 3; // 3 表示整数常数，4 表示浮点数常数
    } else if (ch == '"') {
        token += ch;
        readChar();
        while (ch != '"' && ch != '\n' && ch != '\0') {
            token += ch;
            readChar();
        }
        if (ch == '"') {
            token += ch;
            syn = 3; // 字符串常量
        } else {
            syn = -1; // 错误
        }
    } else {
        switch (ch) {
            case '<': token += ch;
                 readChar();
                if (ch == '>') {
                    syn = 4; // 不等号
                    token += ch;
                } else if (ch == '=') {
                    syn = 4; // 小于等于
                    token += ch;
                } else {
                    syn = 4; // 小于
                    unreadChar(); // 回退一个字符
                }
                break;
            case '>': token += ch;
                readChar();
                if (ch == '=') {
                    syn = 4; // 大于等于
                    token += ch;
                } else {
                    syn = 4; // 大于
                    unreadChar(); // 回退一个字符
                }
                break;
            case ':': token += ch;
                readChar();
                if (ch == '=') {
                    syn = 4; // 赋值
                    token += ch;
                } else {
                    syn = 4; // 冒号
                    unreadChar(); // 回退一个字符
                }
                break;
            case '+': token += ch;
                readChar();
                if (isdigit(ch)) {
                    bool isFloat = false;
                    // 处理正号
                    while (isdigit(ch) || ch == '.' || ch == 'e' || ch == 'E') {
                        if (ch == '.') {
                            if (isFloat) {
                                break; // 如果已经是浮点数，再次遇到小数点则停止
                            }
                            isFloat = true;
                        }
                        if (ch == 'e' || ch == 'E') {
                            token += ch;
                            readChar();
                            if (ch == '+' || ch == '-') {
                                token += ch;
                                readChar();
                            }
                            while (isdigit(ch)) {
                                token += ch;
                                readChar();
                            }
                            break;
                        }
                        token += ch;
                        readChar();
                    }
                    unreadChar(); // 回退一个字符
                    syn = isFloat ? 3 : 3; // 3 表示整数常数，4 表示浮点数常数
                } else if (ch == '+') {
                    syn = 4; // 自增
                    token += ch;
                } else {
                    syn = 4; // 加法
                    unreadChar(); // 回退一个字符
                }
                break;
            case '-': token += ch;
                readChar();
                if (isdigit(ch)) {
                    bool isFloat = false;
                    // 处理负号
                    while (isdigit(ch) || ch == '.' || ch == 'e' || ch == 'E') {
                        if (ch == '.') {
                            if (isFloat) {
                                break; // 如果已经是浮点数，再次遇到小数点则停止
                            }
                            isFloat = true;
                        }
                        if (ch == 'e' || ch == 'E') {
                            token += ch;
                            readChar();
                            if (ch == '+' || ch == '-') {
                                token += ch;
                                readChar();
                            }
                            while (isdigit(ch)) {
                                token += ch;
                                readChar();
                            }
                            break;
                        }
                        token += ch;
                        readChar();
                    }
                    unreadChar(); // 回退一个字符
                    syn = isFloat ? 3 : 3; // 3 表示整数常数，4 表示浮点数常数
                } else if (ch == '-') {
                    syn = 4; // 自减
                    token += ch;
                } else {
                    syn = 4; // 减法
                    unreadChar(); // 回退一个字符
                }
                break;
            case '*': syn = 4; token = "*"; break; // 乘法
            case '/': syn = 4; token = "/"; break; // 除法
            case '=': syn = 4; token = "="; break; // 等号
            case ';': syn = 5; token = ";"; break; // 分号
            case ',': syn = 5; token = ","; break; // 逗号
            case '(': syn = 5; token = "("; break; // 左括号
            case ')': syn = 5; token = ")"; break; // 右括号
            case '{': syn = 5; token = "{"; break; // 左花括号
            case '}': syn = 5; token = "}"; break; // 右花括号
            case '[': syn = 5; token = "["; break; // 左中括号
            case ']': syn = 5; token = "]"; break; // 右中括号
            case '.': syn = 5; token = "."; break; // 点
            case '\'': syn = 5; token = "'"; break; // 单引号
            case '"': syn = 5; token = "\""; break; // 双引号
            case '&': token += ch;
                readChar();
                if (ch == '&') {
                    syn = 4; // 逻辑与
                    token += ch;
                } else {
                    syn = 4; // 位与
                    unreadChar(); // 回退一个字符
                }
                break;
            case '#': token += ch;
                readChar();
                if (ch == 'i') {
                    token += ch;
                    readChar();
                    if (token == "#i") {
                        while (isalnum(ch)) {
                            token += ch;
                            readChar();
                        }
                        if (token == "#include") {
                            while (ch != '\n' && ch != '\0') {
                                token += ch;
                                readChar();
                            }
                            unreadChar(); // 回退一个字符
                            syn = 6; // 头文件
                        } else {
                            syn = 0; // 结束符
                        }
                    } else {
                        syn = 0; // 结束符
                    }
                } else {
                    syn = 0; // 结束符
                }
                break;
            case '\n': syn = -2; row++; break; // 换行符
            default: syn = -1; token = "ERROR"; break; // 错误字符
        }
    }
    return {syn, token};
}