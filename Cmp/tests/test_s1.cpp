#include <gtest/gtest.h>
#include "../s1/s1.h"

// ��������������ȫ�ֱ���
void setProg(const char* input) {
    strcpy(prog, input);
    p = 0;
    m = 0;
    row = 1;
    sum = 0;
}

// ����ʶ��ؼ���
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

// ����ʶ���ʶ��
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

// ����ʶ������
TEST(ScannerTest, RecognizesNumbers) {
    setProg("12345#");
    scaner();
    EXPECT_EQ(syn, 3);
    EXPECT_EQ(sum, 12345);
}

// ����ʶ��������ͷ���
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

// ���Դ������������ַ�
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