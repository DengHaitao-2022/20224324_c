#include <iostream>
using namespace std;
//输出宽为n,高为n正方形
int main(){
	int n;
	cout <<"请输入n的值:";
	cin >>n;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout << "#";
		}
		cout << "\n";
	}
	cout << "\n";
	system("pause");
	return 0;
}

