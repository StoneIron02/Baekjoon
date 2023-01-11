#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	vector<int> v;

	while (true) {
		int a, b;
		cin >> a >> b;
		if (a == 0 && b == 0)
			break;
		v.push_back(a + b);
	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
}