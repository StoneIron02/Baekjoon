#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		vector<int> v(10);
		for (int j = 0; j < 10; j++) {
			cin >> v[j];
		}
		sort(v.begin(), v.end(), greater<>{});
		cout << v[2] << "\n";
	}
}