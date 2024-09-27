#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1000005;
bool is_prime[MAXN];
vector<int> primes;

void sieve() {
	memset(is_prime, true, sizeof(is_prime));
	is_prime[0] = is_prime[1] = false;
	for(int i = 2; i * i < MAXN; i++) {
		if(is_prime[i]) {
			for(int j = i * i; j < MAXN; j += i) {
				is_prime[j] = false;
			}
		}
	}
	for(int i = 2; i < MAXN; i++) {
		if(is_prime[i]) {
			primes.push_back(i);
		}
	}
}

int main() {
	sieve();
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		bool is_semi_prime = false;
		for(int i = 0; i < primes.size() && primes[i] * primes[i] <= n; i++) {
			if(n % primes[i] == 0 && is_prime[n / primes[i]]) {
				is_semi_prime = true;
				break;
			}
		}
		cout << (is_semi_prime ? "Yes" : "No") << endl;
	}
	return 0;
}
