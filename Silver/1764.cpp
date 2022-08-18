#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	set<string> notCall;
	for (int i = 0; i < n; i++) {
		string name;
		cin >> name;
		notCall.insert(name);
	}

	set<string> notAll;
	for (int i = 0; i < m; i++) {
		string name;
		cin >> name;
		if (notCall.find(name) != notCall.end()) {
			notAll.insert(name);
		}
	}

	cout << notAll.size() << "\n";
	for (auto i : notAll) {
		cout << i << "\n";
	}
}