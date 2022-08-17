#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;

	int count = 0;
	for (int i = 0; i < str.size(); i++) {
		count++;
		if (i == 0) continue;
		if (str[i] == '=') {
			if (str[i - 1] == 'c' || str[i - 1] == 's' || str[i - 1] == 'z') {
				count--;
				if (i >= 2) {
					if (str[i - 2] == 'd' && str[i - 1] == 'z') {
						count--;
					}
				}
			}
		}
		else if (str[i] == '-') {
			if (str[i - 1] == 'c' || str[i - 1] == 'd') {
				count--;
			}
		}
		else if (str[i] == 'j') {
			if (str[i - 1] == 'l' || str[i - 1] == 'n') {
				count--;
			}
		}
	}
	cout << count << endl;
}