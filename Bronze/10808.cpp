#include <iostream>
#include <string>
using namespace std;

unsigned int alphabet[26] {0};

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	string str;
	cin >> str;
	for (char c : str) {
		alphabet[c - 'a']++;
	}
	for (int i = 0; i < 26; i++)
		cout << alphabet[i] << " ";
}