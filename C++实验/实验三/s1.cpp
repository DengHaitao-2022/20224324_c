#include <iostream>
using namespace std;

int main(){
	int n;
	cout << "输入正整数n:";
	while(cin >> n){
		int sum=0;
		for(int i=1;i<=n;i++){
			int	num=1;
			for(int j=1;j<=i;j++){
				num *= j;
			}
		sum += num;	
		}
		cout << sum << endl;
	} 

	system("pause");
	return 0;
}

