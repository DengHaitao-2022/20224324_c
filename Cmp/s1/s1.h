#ifndef S1_H
#define S1_H

#include <string>
#include <utility>
#include <unordered_set>

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

    const char* rwtab[68] = { "if", "int", "for", "while", "do", "return", "break", "continue","double",
        "else", "switch", "case", "default", "goto", "sizeof", "typedef",
        "struct", "union", "enum", "const", "volatile", "static", "extern",
        "auto", "register", "signed", "unsigned", "short", "long", "float",
        "double", "char", "void", "inline", "restrict", "asm", "bool", "complex",
        "imaginary", "alignas", "alignof", "atomic", "noreturn", "thread_local",
        "static_assert", "constexpr", "decltype", "namespace", "using", "class",
        "public", "private", "protected", "virtual", "explicit", "friend",
        "operator", "template", "typename", "try", "catch", "throw", "new",
        "delete", "this", "true", "false", "nullptr"
    
   }; // 关键字表


    // const std::unordered_set<std::string> keywords = {
    //     "alignas", "alignof", "and", "and_eq", "asm", "atomic_cancel", "atomic_commit", "atomic_noexcept",
    //     "auto", "bitand", "bitor", "bool", "break", "case", "catch", "char", "char8_t", "char16_t", "char32_t",
    //     "class", "compl", "concept", "const", "consteval", "constexpr", "constinit", "const_cast", "continue",
    //     "co_await", "co_return", "co_yield", "decltype", "default", "delete", "do", "double", "dynamic_cast",
    //     "else", "enum", "explicit", "export", "extern", "false", "float", "for", "friend", "goto", "if",
    //     "inline", "int", "long", "mutable", "namespace", "new", "noexcept", "not", "not_eq", "nullptr", "operator",
    //     "or", "or_eq", "private", "protected", "public", "register", "reinterpret_cast", "requires", "return",
    //     "short", "signed", "sizeof", "static", "static_assert", "static_cast", "struct", "switch", "synchronized",
    //     "template", "this", "thread_local", "throw", "true", "try", "typedef", "typeid", "typename", "union",
    //     "unsigned", "using", "virtual", "void", "volatile", "wchar_t", "while", "xor", "xor_eq"
    // };

    const char* rwtab1[8] = { "main","a","b","c","d","e","f","g" }; // 标识符表
};

#endif // S1_H