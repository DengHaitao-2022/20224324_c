#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

/**列出所有因子数(包含它自身的所有因子的个数)*/
int main() {
	ll n;
	while(cin >> n) {
		int count = 0;
		for(ll i = 1; i * i <= n; i++) {
			if(n % i == 0) {
				if(n / i == i) {
					count++;
				} else {
					count += 2;
				}
			}
		}
		cout << n << ":" << count << endl;
	}
	return 0;
}
