#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	set<string> s;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		s.insert(str);
	}
	int count = 0;
	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		if (s.find(str) != s.end())
			count++;
	}
	cout << count;
}