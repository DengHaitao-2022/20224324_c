#include <iostream>

int main() {
	char c;
	int height;
	
	while (std::cin >> c >> height) {
		// 输出每行的背靠背字符三角形
		for (int i = 1; i <= height; ++i) {
			// 输出空格
			for (int j = 0; j < height - i; ++j) {
				std::cout << " ";
			}
			// 输出字符
			for (int k = 0; k < i; ++k) {
				std::cout << c;
			}
			// 输出空格
			std::cout << " ";
			// 输出字符
			for (int k = 0; k < i; ++k) {
				std::cout << c;
			}
			// 换行
			std::cout << std::endl;
		}
	}
	
	return 0;
}
