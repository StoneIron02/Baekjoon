#include <iostream>
#include <string>
using namespace std;

int main() {
	int t;
	cin >> t;

	for (int n = 0; n < t; n++) {
		int r;
		cin >> r;
		string str;
		cin >> str;

		string result = "";
		for (int i = 0; i < str.size(); i++) {
			for (int j = 0; j < r; j++) {
				result.push_back(str[i]);
			}
		}
		cout << result << endl;
	}

	
}