#include <bits/stdc++.h>
//#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	// 请在此输入您的代码
	string str;
	int a[30]={0};
	int num=0,max=0;
	while(cin>>str){
	//	cout<<str;
		for(int i=0;i<=str.length();i++){
		//	int num = (int)str[i];
		//	printf("%d",num);
			a[str[i]-'a']++;
			
		}
		for(int j=0;j<=26;j++){
			
		//	printf("%d",a[j]);
			if(a[j]>max){
				max=a[j];
				num=j+97;
			}
		}
		char w=(char)num;
		cout<<w<<endl;
		cout<<max;
		fill_n(a,26,0);
		num=0;
		max=0;
	}
	return 0;
	
}
