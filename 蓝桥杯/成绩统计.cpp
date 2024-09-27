#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,num,i,j=0,g=0,u=0;
	//TODO
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num;
		j++;
		if(num>=85){
			g++;
		}
		if(num>=60){
			u++;
		}
		
	}
	//printf("优秀人数:%d,及格人数:%d ",g,u);
	float a,b;
	a=g*1.0/j*100;
	b=u*1.0/j*100;
	printf("%2.f\%\n",b);
	printf("%2.f\%\n",a);
	
}
