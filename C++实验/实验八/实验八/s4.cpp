#include <iostream>

// 计算可以创建的侦查小组的数量
int scout_groups(int N) {
	if (N <= 3) {
		return 1;
	} else if (N % 2 == 0) {
		return 1;
	} else {
		return 2;
	}
}

int main() {
	int N;
	
	// 读取输入的士兵数量
	while (std::cin >> N) {
		// 计算并输出可以创建的侦查小组的数量
		std::cout << scout_groups(N) << std::endl;
	}
	
	return 0;
}
