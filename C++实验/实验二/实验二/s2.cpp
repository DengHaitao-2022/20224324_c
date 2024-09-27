#include <iostream>

int main() {
	char c;
	int side_length;
	
	while (std::cin >> c >> side_length) {
		// 上半部分
		for (int i = 1; i <= side_length; ++i) {
			// 输出空格
			for (int j = 0; j < side_length - i; ++j) {
				std::cout << " ";
			}
			// 输出字符
			for (int k = 0; k < 2 * i - 1; ++k) {
				std::cout << c;
			}
			std::cout << std::endl; // 换行
		}
		// 下半部分
		for (int i = side_length - 1; i >= 1; --i) {
			// 输出空格
			for (int j = 0; j < side_length - i; ++j) {
				std::cout << " ";
			}
			// 输出字符
			for (int k = 0; k < 2 * i - 1; ++k) {
				std::cout << c;
			}
			std::cout << std::endl; // 换行
		}
	}
	
	system("pause");
	return 0;
}
