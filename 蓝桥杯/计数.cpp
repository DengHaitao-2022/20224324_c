#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b,n;
	int da;
	while(cin>>a>>b>>n){
		int day[7]={a,a,a,a,a,b,b};
		/*for(int j=0;j<=7;j++){
		printf("%d ",day[j]);
		}*/
	
		for(int i=0;i<=n;i++){
			int d;
			d = i%7;
			i += day[d-1];
			da++;
		}
	cout<<da;
		da=0;
	}
}
