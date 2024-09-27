#include <gtest/gtest.h>
#include "../s1/s1.h"

// 辅助函数来设置全局变量
void setProg(const char* input) {
    strcpy(prog, input);
    p = 0;
    m = 0;
    row = 1;
    sum = 0;
}

// 测试识别关键字
TEST(ScannerTest, RecognizesKeywords) {
    setProg("if#");
    scaner();
    EXPECT_EQ(syn, 1);
    EXPECT_STREQ(token, "if");

    setProg("while#");
    scaner();
    EXPECT_EQ(syn, 1);
    EXPECT_STREQ(token, "while");
}

// 测试识别标识符
TEST(ScannerTest, RecognizesIdentifiers) {
    setProg("main#");
    scaner();
    EXPECT_EQ(syn, 2);
    EXPECT_STREQ(token, "main");

    setProg("variable123#");
    scaner();
    EXPECT_EQ(syn, 2);
    EXPECT_STREQ(token, "variable123");
}

// 测试识别数字
TEST(ScannerTest, RecognizesNumbers) {
    setProg("12345#");
    scaner();
    EXPECT_EQ(syn, 3);
    EXPECT_EQ(sum, 12345);
}

// 测试识别操作符和符号
TEST(ScannerTest, RecognizesOperatorsAndSymbols) {
    setProg("<#");
    scaner();
    EXPECT_EQ(syn, 4);
    EXPECT_STREQ(token, "<");

    setProg("<=#");
    scaner();
    EXPECT_EQ(syn, 4);
    EXPECT_STREQ(token, "<=");

    setProg("+#");
    scaner();
    EXPECT_EQ(syn, 4);
    EXPECT_STREQ(token, "+");

    setProg(";#");
    scaner();
    EXPECT_EQ(syn, 5);
    EXPECT_STREQ(token, ";");
}

// 测试处理错误和特殊字符
TEST(ScannerTest, HandlesErrorsAndSpecialCharacters) {
    setProg("@#");
    scaner();
    EXPECT_EQ(syn, -1);

    setProg("\n#");
    scaner();
    EXPECT_EQ(syn, -2);
    EXPECT_EQ(row, 2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}