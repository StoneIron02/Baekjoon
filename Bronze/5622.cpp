#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;

	int sum = 0;
	for (int i = 0; i < str.size(); i++) {
		int n = str[i] - 'A';
		int m;
		if (n < 26) m = 9;
		if (n < 22) m = 8;
		if (n < 19) m = 7;
		if (n < 15) m = 6;
		if (n < 12) m = 5;
		if (n < 9) m = 4;
		if (n < 6) m = 3;
		if (n < 3) m = 2;
		sum += 2 + m - 1;
	}
	cout << sum << endl;
}