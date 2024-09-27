#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;
// 计算n阶勒让德多项式的值
double poly(int n, double x) {
	if (n == 0) {
		return 1;
	} else if (n == 1) {
		return x;
	} else {
		return ((2 * n - 1) * x * poly(n - 1, x) - (n - 1) * poly(n - 2, x)) / n;
	}
}

int main() {
	vector<double> xs;
	double x;
	
	// 读取输入的浮点数
	while (std::cin >> x) {
		xs.push_back(x);
		std::cout << "x\t  "<<"p2(x)\t    "<<"p3(x)\t  "<<"p4(x)\t  "<<"p5(x)\t   "<<"p6(x)\n";

			// 计算并输出n阶勒让德多项式的值
			for (const auto& x : xs) {
				cout << fixed << setprecision(3) << x << "  ";
				for (int n = 2; n <= 6; n++) {
					cout << fixed << setprecision(6) << poly(n, x)<<"  " ;
				}
				cout<<endl;
			}
		
		
	}
	
	// 输出标题行


	
	return 0;
}
