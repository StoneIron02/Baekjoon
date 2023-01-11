#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		cout << str[i];
		if (i % 10 == 9)
			cout << "\n";
	}
}