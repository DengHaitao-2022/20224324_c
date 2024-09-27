#include <iostream>
//输出两个数的差
int main() {
	int num1, num2;
	while (std::cin >> num1 >> num2) {
		int diff = num1 - num2; 
		std::cout << diff << std::endl; // 输出差值并换行
	}
	system("pause");
	return 0;
}
