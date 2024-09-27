#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,a,x=0,j;
	int num[10]={0};
	cin>>a;
	for(int i=0;i<=9;i++){
		num[i]=a;
	}
	for(j=1;;j++){
		x=j;
		while(x){
			//cout<<x<<endl;
			if(num[x%10]==-1){
				cout<<j-2;
				//break;
				exit(0);
			}
			/*for(int i=0;i<=9;i++){
				cout<<num[i];
			}
			cout<<endl;*/
			num[x%10]--; 
			x/=10;	

		}
	}
	//cout<<j;
	return 0;
}
