#include <iostream>
using namespace std;
int main() {
	char c;
	int h;
	cout <<"输入字符和行数:";
	while (cin >> c >> h) {
		// 输出等腰三角形
		for (int i = 1; i <= h; ++i) {
			// 输出空格
			for (int j = 0; j < h - i; ++j) {
				cout << " ";
			}
			// 输出字符
			for (int k = 0; k < 2 * i - 1; ++k) {
				cout << c;
			}
			cout << endl; // 换行
		}
	}
	
	system("pause");
	return 0;
}
