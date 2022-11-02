#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	string str;
	cin >> str;
	int num = 0;
	for (char c : str) {
		num *= 16;
		if (c >= 'A')
			num += c - 'A' + 10;
		else
			num += c - '0';
	}
	cout << num;
}