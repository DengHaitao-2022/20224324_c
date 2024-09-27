#include <iostream>
#include <iomanip>

int main() {
	int n;
	
	while (std::cin >> n) {
		// 输出格式阵列
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n ; ++j) {
				std::cout << "(" << i << "," << j << ")";
				if (j < n) {
					std::cout << " ";
				}
			}
			std::cout << std::endl;
		}
		std::cout << std::endl; // 输出空行
	}
	
	return 0;
}
