#include <iostream>
#include <set>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	for (int w = 0; w < t; w++) {
		set<int> set;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			set.insert(num);
		}
		int m;
		cin >> m;
		for (int i = 0; i < m; i++) {
			int num;
			cin >> num;
			if (set.find(num) != set.end())
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
	}
}