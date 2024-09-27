//判断每个整数是否能整除3.5.7
#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int n;
	while(cin>>n){
		//枚举
		cout<<n<<"-->";
		if(n%3==0&&n%5==0&&n%7==0){
			printf("3,5,7\n");
		}else if(n%3==0&&n%5==0){
			printf("3,5\n");
		}else if(n%3==0&&n%7==0){
			printf("3,7\n");
		}else if(n%5==0&&n%7==0){
			printf("5,7\n");
		}else if(n%3==0){
			printf("3\n");
		}else if(n%7==0){
			printf("7\n");
		}else if(n%5==0){
			printf("5\n");
		}else
			printf("None\n");
		
	}
	
	return 0;
}
