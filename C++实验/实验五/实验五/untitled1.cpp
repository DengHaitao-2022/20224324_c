#include <bits/stdc++.h>
using namespace std;

string f(int n){
	if(n==1){
		return "A";
		//TODO
	}else{
		return f(n-1)+(char)('A'+n+1)+f(n-1);
	}
}

int main(){
	int n;
	while(cin>>n){
		cout<<f(n)<<endl;
		//TODO
	}
}
