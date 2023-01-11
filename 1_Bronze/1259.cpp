#include <iostream>
#include <string>
using namespace std;

int main() {
	while (true) {
		string str;
		cin >> str;
		if (str == "0") break;
		bool correct = true;
		for (int i = 0; i < str.size() / 2; i++) {
			char left = str[i];
			char right = str[str.size() - i - 1];
			if (str[i] != str[str.size() - i - 1]) {
				correct = false;
			}
		}
		if (correct)
			cout << "yes\n";
		else
			cout << "no\n";
	}
}