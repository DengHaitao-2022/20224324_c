#include <iostream>
using namespace std;
main(){
	int a, b,c;
	while(cin>>a>>b){
		
		while(b){
			c = a % b;
			a=b;
			b=c;
		}	
	cout<<a<<endl;

	}
	return 0;
}
