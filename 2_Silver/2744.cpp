#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	string str;
	cin >> str;
	for (char c : str) {
		if (c >= 'a' && c <= 'z')
			cout << (char)(c - 'a' + 'A');
		else
			cout << (char)(c - 'A' + 'a');
	}
}