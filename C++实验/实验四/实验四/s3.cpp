//对于输入的n,输出第n年的母牛数(递归计算)
#include <iostream>
#include <cmath>
using namespace std;


// 计算第n年有多少母牛
int countCows(int n) {
	if (n <= 3) {
		// 前三年只有1头母牛
		return 1;
	} else if (n == 4) {
		// 第四年有2头母牛
		return 2;
	} else {
		// 第n年的母牛数量等于第n-1年的母牛数量加上第n-4年的母牛数量
		return countCows(n - 1) + countCows(n - 3);//应该加上的是n-3年的
	}
}

int main() {
	int n;

	while(cin >> n){
	cout << "第" << n << "年有 " << countCows(n) << " 头母牛。" << endl;
	}
	return 0;
}

/*
  int main(void){
	int n;
	while(cin>>n){
		int y,sum,cow=1;
		y=n/4;
		if(y>=1){
			sum = pow(2,y);
		}
		else{}
		cow+=sum;
		cout<<cow<<endl;
	}
	
	return 0;
}
 */
