//对称三位素数

#include <iostream>
#include <cmath>
using namespace std;

//判断是否为素数
bool num(int n){
	int sqr = sqrt(n*1.0);
	for(int i=2;i<=sqr;i++){
		if(n%i == 0){
			return false;
		}
		else{
			return true;
		}
	}
	
}


int main(void){
	
	int n;
	while(cin>>n){
		if(n>=100&&n<=999&&num(n)&&n%10==n/100){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
		
	}
	
	return 0;
}
