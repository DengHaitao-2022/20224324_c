#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// 检查字符串是否是对称的
bool is_palindrome(const std::string& s) {
	int i = 0, j = s.size() - 1;
	while (i < j) {
		if (s[i] != s[j]) {
			return false;
		}
		i++;
		j--;
	}
	return true;
}

int main() {
	std::vector<std::string> palindromes;
	std::string s;
	
	// 读取输入的字符串
	while (std::cin >> s) {
		// 如果字符串是对称的，将其添加到列表中
		if (is_palindrome(s)) {
			palindromes.push_back(s);
		}
	}
	
	// 对列表进行排序
	std::sort(palindromes.begin(), palindromes.end(), [](const std::string& a, const std::string& b) {
		if (a.size() != b.size()) {
			return a.size() < b.size();
		} else {
			return a < b;
		}
	});
	
	// 输出排序后的对称字符串
	for (const auto& palindrome : palindromes) {
		std::cout << palindrome << std::endl;
	}
	
	return 0;
}
