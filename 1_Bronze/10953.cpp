#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	cin.get();
	for (int i = 0; i < t; i++) {
		string str;
		getline(cin, str);
		int a = str[0] - '0';
		int b = str[2] - '0';
		cout << a + b << "\n";
	}
}