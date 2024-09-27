#include <iostream>
#include <vector>
using namespace std;

// 计算给定数字的阶乘
vector<int> calculateFactorial(int n) {
	vector<int> result;
	result.push_back(1); // 初始化结果为1
	
	for (int i = 2; i <= n; ++i) {
		int carry = 0;
		for (int j = 0; j < result.size(); ++j) {
			int product = result[j] * i + carry;
			result[j] = product % 10;
			carry = product / 10;
		}
		while (carry > 0) {
			result.push_back(carry % 10);
			carry /= 10;
		}
	}
	return result;
}

// 计算给定数字的数字个数
int countDigits(const vector<int>& num) {
	return num.size();
}

int main() {
	int n;
	while(cin >> n){
	
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		
		vector<int> factorial = calculateFactorial(num);
		cout << countDigits(factorial) << endl;
	}
	}	
	return 0;
}
