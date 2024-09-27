#include <iostream>
#include <cmath>
#include <iomanip>
#include <bitset>
using namespace std;

int main(void){
	//短除法十进制转化为二进制
	int n,i,j;
	int o[32]={0};
	while(cin>>n){
		int a=n;
		for(i=0;n>0;i++){
			o[i]=n%2;
			n/=2;
			
		}
		for(int j=i-1;j>=0;j--){
			/*int i=0;
			o[j]=o[i];
			  i++;*/
			cout<<o[j];
		}
		//cout<<"  "<<a<<endl;
		cout<<bitset<32>(a)<<"  "<<a<<endl;
	}
	system("pause");
	return 0;
}




