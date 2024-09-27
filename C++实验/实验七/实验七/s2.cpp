#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// 排序函数，首先比较字符串的长度，然后比较字符串中 '1' 的个数，最后比较字符串的 ASCII 码值
bool compare(const std::string& a, const std::string& b) {
	// 如果两个字符串的长度不同，长度短的排在前面
	if (a.size() != b.size())
		return a.size() < b.size();
	// 计算每个字符串中 '1' 的个数
	int countA = std::count(a.begin(), a.end(), '1');
	int countB = std::count(b.begin(), b.end(), '1');
	// 如果两个字符串中 '1' 的个数不同，'1' 的个数少的排在前面
	if (countA != countB)
		return countA < countB;
	// 如果两个字符串的长度和 '1' 的个数都相同，就按照 ASCII 码值排序
	return a < b;
}

int main() {
	// 存储输入的 01 串
	std::vector<std::string> strings;
	std::string str;
	// 读取输入的 01 串
	while (std::cin >> str) {
		strings.push_back(str);
	}
	
	// 使用自定义的排序函数对 01 串进行排序
	std::sort(strings.begin(), strings.end(), compare);
	
	// 打印排序后的 01 串
	for (const auto& s : strings) {
		std::cout << s << std::endl;
	}
	
	return 0;
}
