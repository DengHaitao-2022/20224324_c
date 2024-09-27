#include<bits/stdc++.h>
using namespace std;
/**输出所有不大于n的完数*/
int main(){
	int n,i=1,sum;
	
	while(cin>>n){
		cout<<n<<":";
		for(i=1;i<=n;i++){
			sum=0;
			
			for(int j=1;j<i;j++){
				if(i%j==0){
					sum+=j;
					//cout<<i<<" "<<j<<' '<<sum<<endl;	
				}
				
			}
			if(sum==i){
				cout<<i<<" ";
			}
				
		
			
		}
		cout<<endl;
	}
	
	return 0;
}
