#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	string str;
	cin >> str;

	int sum = 0;
	for (int i = 0; i < n; i++) {
		int num = str[i] - '0';
		sum += num;
	}
	cout << sum;
}