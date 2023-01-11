#include <iostream>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	while (true) {
		int a, b;
		cin >> a >> b;
		if (a == 0 && b == 0)
			exit(0);
		if (a > b)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}