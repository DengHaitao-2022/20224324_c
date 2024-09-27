//对于每个x，输出其级数和，所有绝对值小于10的-6次方的数值不应加入级数和中
#include <iostream>
#include <cmath>
using namespace std;

int main(void){
	int n;
	float a,sum,x;
	
	while(cin>>x){
		sum = 1;
		a = x;
		for(int n=1;abs(a)>=1e-6;){
			sum = sum + a;
			++n;//如果放在for循环结构体里面会少一次
			a = a * ((-1)*x/n);
		}
	
		//cout<<"x="<<x<<"sum="<<sum<<endl;
		cout<<"x="<<fixed<<x<<"sum="<<fixed<<sum<<endl;
	}
	system("pause");
	return 0;
}
