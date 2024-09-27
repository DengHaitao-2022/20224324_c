#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
	float n,p;
	float sn;
	cout << "输入正整数n:";
	while(cin >> n >> p){
		if(n <= 0 || p <= 0){
			cout << "输入错误" << endl;
			
		}
		float num = pow(p,n);

		sn = (1-num)/(1-p);
		printf("%.3f\n",sn);
	}
	return 0;
}
