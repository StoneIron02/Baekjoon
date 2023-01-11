#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	string str;
	cin >> str;
	int sum = 0;
	bool minus = false;
	int start = 0;
	for (int i = 1; i <= str.size(); i++) {
		if (i == str.size() || str[i] == '+' || str[i] == '-') {
			int num = stoi(str.substr(start, i - start + 1));
			if (minus)
				sum -= num;
			else {
				sum += num;
				if (str[i] == '-')
					minus = true;
			}
			start = i + 1;
		}
	}
	cout << sum;
}