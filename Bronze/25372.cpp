#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		string str;
		cin >> str;
		if (str.size() < 6 || str.size() > 9)
			cout << "no\n";
		else
			cout << "yes\n";
	}
}