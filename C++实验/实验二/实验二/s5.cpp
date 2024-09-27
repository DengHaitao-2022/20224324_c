#include <iostream>

void print(int n) {
	int count = 0;
	for (int i = 0; i < n; ++i) {
		int row_num = i + 1;
		// 打印行号
		if(row_num < 10) std::cout << " ";
		std::cout << row_num << " ";
		// 打印每行元素
		for (int j = 0; j < n; ++j) {
			std::cout << (count % n) << " ";
			count = (count + 1) % n;
		}
		std::cout << std::endl;
		// 更新count
		count = (count  + 1) % n;
	}
}

int main() {
	int n;
	while (std::cin >> n) {
		print(n);
		std::cout << std::endl; // 输出空行
	}
	return 0;
}
