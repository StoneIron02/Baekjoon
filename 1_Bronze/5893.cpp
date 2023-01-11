#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	// b17 = "10001" => n << 4 + n
	string n;
	cin >> n;
	string n_lshift4 = n + "0000";
	n = "0000" + n;

	string result = "";
	int over = 0;
	for (int i = n.size() - 1; i >= 0; i--) {
		int val1 = n[i] - '0';
		int val2 = n_lshift4[i] - '0';
		int val = val1 + val2 + over;
		if (val > 1) {
			over = 1;
			val -= 2;
		}
		else {
			over = 0;
		}
		result = to_string(val) + result;
	}
	if (over == 1)
		result = "1" + result;
	cout << result;
}