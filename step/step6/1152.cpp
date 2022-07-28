#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	getline(cin, str);

	int count = 0;
	bool construct = false;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ' ') {
			if (construct) count++;
			construct = false;
		}
		else
			construct = true;
	}
	if (construct) count++;
	cout << count << endl;
}