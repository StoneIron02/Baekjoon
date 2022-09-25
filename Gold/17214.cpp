#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	string str;
	cin >> str;
	int x[2] = { 0 };
	int xCount = 0;
	int index = 1;
	int pm = 1;
	int num = 0;
	for (int i = 0; i < str.size(); i++) {
		char c = str[i];
		if (c == 'x') {
			xCount++;
			if (i == 0 || str[i - 1] == '+' || str[i - 1] == '-')
				x[xCount] = pm;
			else
				x[xCount] = pm * num;
			xCount = 0;
			pm = 1;
			num = 0;
		}
		else if (c == '+')
			pm = 1;
		else if (c == '-')
			pm = -1;
		else {
			num *= 10;
			int n = (c - '0');
			num += n;
		}
	}
	x[xCount] = pm * num;

	if (x[1] != 0) {
		int num = x[1] / 2;
		if (num == 1)
			cout << "xx";
		else if (num == -1)
			cout << "-xx";
		else
			cout << (x[1] / 2) << "xx";
	}

	if (x[0] != 0) {
		if (x[1] != 0) {
			if (x[0] > 0)
				cout << "+";
		}
		if (x[0] == 0)
			;
		else if (x[0] == 1)
			cout << "x";
		else if (x[0] == -1)
			cout << "-x";
		else
			cout << x[0] << "x";
	}

	if (x[0] != 0 || x[1] != 0) {
		cout << "+";
	}
	cout << "W";
}