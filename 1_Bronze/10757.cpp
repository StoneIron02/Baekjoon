#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;

	int n = a.length() > b.length() ? a.length() : b.length();
	for (int i = a.length(); i < n; i++)
		a.insert(0, "0");
	for (int i = b.length(); i < n; i++)
		b.insert(0, "0");

	stack<char> result;
	int upper = 0;
	for (int i = n - 1; i >= 0; i--) {
		int num = (a[i] - '0') + (b[i] - '0') + upper;
		if (num >= 10) {
			upper = 1;
			num %= 10;
		}
		else {
			upper = 0;
		}
		result.push(num + '0');
	}
	if (upper == 1)
		result.push('1');

	for (int i = result.size(); i > 0; i--) {
		cout << result.top();
		result.pop();
	}
	cout << endl;
}