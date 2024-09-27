#include <iostream>
//正方形的面积(输入以空格间隔的数据)


int main() {
	int num;
	std::cout <<"请输入边长(输入以空格间隔的数据):";
	while (std::cin >> num) {
		int area = num * num; 
		std::cout << area << std::endl; // 输出面积数并换行
	}
	system("pause");
	return 0;
}
