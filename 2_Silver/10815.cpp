#include <iostream>
#include <set>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	set<int> s;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		s.insert(num);
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		cout << (s.find(num) != s.end()) << " ";
	}
}