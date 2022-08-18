#include <iostream>
#include <set>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	set<int> all;
	set<int> A;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		A.insert(num);
		all.insert(num);
	}

	set<int> containBoth;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		if (A.find(num) != A.end()) {
			containBoth.insert(num);
		}
		all.insert(num);
	}

	for (auto i : containBoth) {
		all.erase(i);
	}
	cout << all.size();
}