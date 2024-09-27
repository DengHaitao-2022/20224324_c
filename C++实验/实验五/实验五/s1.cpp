#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,i;
	while(cin>>n){
		printf("%12d-->",n);
		double c = 0;
		for(int i=0;;i++){
			c+=(n%2)*pow(10,i);
			n/=2;
			if(n==0){
				break;
			}	
		}
		cout<<c<<endl;
		
	}
	return 0;
}
