#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;
	vector<string> origin;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		origin.push_back(str);
	}

	int length = origin[0].size();
	for (int i = 1; i < length; i++) {
		set<string> subset;
		int flag = true;
		for (string str : origin) {
			string sub = str.substr(length - i);
			if (subset.find(sub) != subset.end()) {
				flag = false;
				break;
			}
			subset.insert(sub);
		}
		if (flag) {
			cout << i;
			exit(0);
		}
	}
	cout << length;
}