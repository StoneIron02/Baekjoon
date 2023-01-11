#include <iostream>
#include <string>
using namespace std;

int main() {
	string str1, str2;
	cin >> str1 >> str2;
	int n1 = 0, n2 = 0;
	for (int i = 2; i >= 0; i--) {
		n1 *= 10;
		n1 += str1[i] - '0';
		n2 *= 10;
		n2 += str2[i] - '0';
	}

	if (n1 > n2)
		cout << n1 << endl;
	else
		cout << n2 << endl;
}