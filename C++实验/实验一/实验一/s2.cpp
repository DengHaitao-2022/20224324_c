#include <iostream>
//输出宽为20,高为n矩形
int main(){
	int n;
	std::cin >>n;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<20;j++){
			std::cout << "@";
		}
	std::cout << std::endl;
	}
std::cout << std::endl;
}

