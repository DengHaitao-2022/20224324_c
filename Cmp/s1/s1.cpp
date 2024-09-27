#include "s1.h"
#include <iostream>
#include <cstring>
using namespace std;

char prog[80], token[20]; // token储存当前识别字符串
char ch;
int syn, p, m = 0, n, row = 1, sum = 0;  // syn: 单词种别码, p: prog的索引, m: token的索引, n: 循环变量, row: 行号, sum: 数字值
const char* rwtab[8] = { "if","int","for","while","do","return","break","continue" }; 
const char* rwtab1[8] = { "main","a","b","c","d","e","f","g" };

void scaner()
{
    for (n = 0; n < 20; n++) token[n] = '\0';
    ch = prog[p++];
    while (ch == ' ')
    {
        ch = prog[p++];
    }
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
    {
        m = 0;
        while ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
        {
            token[m++] = ch;
            ch = prog[p++];
        }
        token[m] = '\0'; // 结束符
        p--; // 回退一个字符
        syn = 2; // 默认是标识符
        for (n = 0; n < 8; n++)
        {
            if (strcmp(token, rwtab[n]) == 0)
            {
                syn = 1; // 关键字
                break;
            }
            else if (strcmp(token, rwtab1[n]) == 0)
            {
                syn = 2; // 标识符
                break;
            }
        }
    }
    else if (ch >= '0' && ch <= '9')
    {
        sum = 0;
        while (ch >= '0' && ch <= '9')
        {
            sum = sum * 10 + ch - '0';
            ch = prog[p++];
        }
        p--; // 回退一个字符
        syn = 3; // 数字
    }
    else switch (ch)
    {
        case '<': m = 0; token[m++] = ch;
            ch = prog[p++];
            if (ch == '>')
            {
                syn = 4; // 不等号
                token[m++] = ch;
            }
            else if (ch == '=')
            {
                syn = 4; // 小于等于
                token[m++] = ch;
            }
            else
            {
                syn = 4; // 小于
                p--;
            }
            break;
        case '>': m = 0; token[m++] = ch;
            ch = prog[p++];
            if (ch == '=')
            {
                syn = 4; // 大于等于
                token[m++] = ch;
            }
            else
            {
                syn = 4; // 大于
                p--;
            }
            break;
        case ':': m = 0; token[m++] = ch;
            ch = prog[p++];
            if (ch == '=')
            {
                syn = 4; // 赋值
                token[m++] = ch;
            }
            else
            {
                syn = 4; // 冒号
                p--;
            }
            break;
        case '*': syn = 4; token[0] = ch; break; // 乘法
        case '/': syn = 4; token[0] = ch; break; // 除法
        case '+': syn = 4; token[0] = ch; break; // 加法
        case '-': syn = 4; token[0] = ch; break; // 减法
        case '=': syn = 4; token[0] = ch; break; // 等号
        case ';': syn = 5; token[0] = ch; break; // 分号
        case ',': syn = 5; token[0] = ch; break; // 逗号
        case '(': syn = 5; token[0] = ch; break; // 左括号
        case ')': syn = 5; token[0] = ch; break; // 右括号
        case '{': syn = 5; token[0] = ch; break; // 左花括号
        case '}': syn = 5; token[0] = ch; break; // 右花括号
        case '#': syn = 0; token[0] = ch; break; // 结束符
        case '\n': syn = -2; row++; break; // 换行符
        default: syn = -1; break; // 错误字符
    }
}