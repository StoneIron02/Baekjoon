#include <iostream>
#include <string>
using namespace std;

bool check(string str) {
	bool* arr = new bool[26];
	for (int j = 0; j < 26; j++)
		arr[j] = false;

	for (int j = 1; j < str.size(); j++) {
		if (str[j] != str[j - 1]) {
			if (arr[str[j] - 'a'])
				return false;
			else
				arr[str[j - 1] - 'a'] = true;
		}
	}
	return true;
}

int main() {
	int count = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		if (check(str))
			count++;
	}
	cout << count << endl;
}