#include <bits/stdc++.h>
using namespace std;

int countDays(string date) {
	// 使用stringstream分割日期字符串
	stringstream ss(date);
	string month, day, year;
	getline(ss, month, '.');
	getline(ss, day, ' ');
	getline(ss, year, ' ');
	printf("%c-%c-%c",month,day,year);
	// 将日期字符串转换为整数
	int dayNum = (int)(day);
	
	// 如果日期为25号，则根据是否有*标记来确定是否计数
	if (dayNum == 25) {
		if (date.back() == '*') {
			return 2; // 如果有*标记，则计数加倍
		} else {
			return 1; // 如果没有*标记，则计数为1
		}
	} else {
		return 0; // 如果不是25号，则不计数
	}
}

int main() {
	string date;
	int totalDays = 0;
	
	cout << "请输入日期（格式为 Mon.DD YYYY）：" << endl;
	while (getline(cin, date)) {
		totalDays += countDays(date);
	}
	
	cout << "符合条件的日期总天数为：" << totalDays << " 天。" << endl;
	
	return 0;
}
