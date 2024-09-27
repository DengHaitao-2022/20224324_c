#include <iostream>
#include <cmath>

int find_min_x(int n) {
	for (int x = 1; x < n; x++) {
		if (static_cast<int>(pow(2, x)) % n == 1) {
			return x;
		}
	}
	return -1;
}

int main() {
	int n;
	std::cin >> n;
	int x = find_min_x(n);
	if (x == -1) {
		std::cout << "2^? mod " << n << " = 1" << std::endl;
	} else {
		std::cout << "2^" << x << " mod " << n << " = 1" << std::endl;
	}
	system("pause");
	return 0;
}

