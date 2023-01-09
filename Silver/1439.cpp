#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	string str;
	cin >> str;
	int num0 = 0, num1 = 0;
	int curNum = str[0];
	if (curNum == '0')
		num0++;
	else
		num1++;
	for (int i = 1; i < str.size(); i++) {
		int newNum = str[i];
		if (curNum != newNum) {
			if (newNum == '0')
				num0++;
			else
				num1++;
		}
		curNum = newNum;
	}

	if (num0 < num1)
		cout << num0;
	else
		cout << num1;
}