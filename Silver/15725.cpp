#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	string str;
	cin >> str;
	int x[2] = {0};
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
	x[xCount] = num;
	cout << x[1];
}