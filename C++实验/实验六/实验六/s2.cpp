#include<bits/stdc++.h>
using namespace std;

/**输出所有两两相乘的积为12!的个数*/
typedef long long ll;

ll factorial[13];

void init() {
	factorial[0] = 1;
	for(int i = 1; i <= 12; i++) {
		factorial[i] = factorial[i-1] * i;
	}
}

int main() {
	init();
	vector<ll> factors;
	ll n;
	while(cin >> n) {
		if(factorial[12] % n == 0) {
			factors.push_back(n);
		}
	}
	int count = 0;
	for(int i = 0; i < factors.size(); i++) {
		for(int j = i+1; j < factors.size(); j++) {
			if(factors[i] * factors[j] == factorial[12]) {
				count++;
			}
		}
	}
	cout << count << endl;
	return 0;
}
