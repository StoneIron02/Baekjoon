#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	string str;
	cin >> str;
	set<string> part;
	for (int len = 1; len <= str.size(); len++) {
		for (int i = 0; i < (str.size() - len + 1); i++) {
			part.insert(str.substr(i, len));
		}
	}
	cout << part.size();
}