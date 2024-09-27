#include <cmath>
#include <iostream>
using namespace std;

// 计算n!的位数
int factorial_digits(int n) {
	if (n < 0)
		return 0;
	else if (n <= 1)
		return 1;
	else {
		// 使用斯特灵公式计算n!的位数
		double x = n * log10(n / M_E) + log10(2 * M_PI * n) / 2.0;
		return floor(x) + 1;
	}
}

int main() {
	int n;
	while(cin>>n){
		cout<<factorial_digits(n)<<endl;
	}
	return 0;
}
