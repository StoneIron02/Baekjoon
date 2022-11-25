#include <iostream>
#include <string>
using namespace std;

int S = 0;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		if (str == "add") {
			int x;
			cin >> x;
			S = S | (1 << x - 1);
		}
		if (str == "remove") {
			int x;
			cin >> x;
			S = S & ~(1 << x - 1);
		}
		if (str == "check") {
			int x;
			cin >> x;
			cout << (bool)(S & (1 << x - 1)) << "\n";
		}
		if (str == "toggle") {
			int x;
			cin >> x;
			S = S ^ (1 << x - 1);
		}
		if (str == "all") {
			S = (1 << 21) - 1;
		}
		if (str == "empty") {
			S = 0;
		}
	}
}