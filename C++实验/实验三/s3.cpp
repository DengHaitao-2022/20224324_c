#include <iostream>
using namespace std;
int main(){
	int a =0;
	int b =1;
	int al;
	int a2;
	int n;
	int ml, m2;
	while(cin >> ml>> m2)
	{
		for(n=3;n<= ml; n++)
		{
			al = a+ b;a2 = al + b;
		a = b;
		b = al;
		}
		cout << a2<< endl;
		a2 = 0;
		a = 0;
		b = 1;
		for(n=3;n<= m2;n++){
		al = a + b;
		a2 = al + b;
		a = b;
		b = al;
		}
		cout<< a2 << endl;
		system("pause");
		return 0;
	}
	system("pause");
	return 0;
}
