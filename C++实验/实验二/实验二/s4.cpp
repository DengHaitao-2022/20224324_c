#include <iostream>

int main() {
	int height;
	
	while (std::cin >> height) {
		char r_char = 'S'; // 初始为'S'
		// 输出倒三角形
		for (int i = height; i >= 1; --i) {
			// 输出字符
			for (int j = 0; j < height - i; ++j) {
				std::cout << " ";
			}
			for (int k = 0; k < 2 * i - 1; ++k) {
				std::cout << r_char;
				// 切换字符
				r_char = (r_char == 'S') ? 'T' : 'S';
			}
				r_char = (r_char == 'S') ? 'T' : 'S';
			//std::cout << std::endl; 
		}
	}
	
	return 0;
}
