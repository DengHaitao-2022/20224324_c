#include <iostream>
//根据读入的字符值，输出以该字符为填充字符的等腰三角形。
int main() {
	char c;
	std::cout <<"请输入字符:";
	std::cin >> c; 
	
	int h = 7;
	int len = 13;
	
	// 输出等腰三角形
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < len + i - 6; ++j) {
			if (j < h - i - 1) {
				std::cout << " ";
			} else {
				std::cout << c;
			}                                
		}
		std::cout << std::endl; 
	}
	std::cout << std::endl; 
	
	system("pause");
	return 0;
}

