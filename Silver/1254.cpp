#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool isPallin(string s, int begin) {
	int n = ceil((s.size() - begin) / 2.0);
	for (int i = 0; i < n; i++) {
		int beginIndex = begin + i;
		int endIndex = s.size() - 1 - i;
		if (s[beginIndex] != s[endIndex]) {
			return false;
		}
	}
	return true;
}

void pallin(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (isPallin(s, i)) {
			cout << (s.size() + i);
			return;
		}
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	string s;
	cin >> s;
	pallin(s);
}