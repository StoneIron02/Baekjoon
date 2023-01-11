#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	string str;
	while (true) {
		getline(cin, str);
		if (str.empty())
			break;
		cout << str << "\n";
	}
}