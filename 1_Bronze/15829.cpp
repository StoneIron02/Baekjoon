#include <iostream>
#include <string>
using namespace std;

unsigned int hashFunction(string str, int l) {
	unsigned int r = 31;
	unsigned int M = 1234567891;
	unsigned long long value = 0;
	for (int i = 0; i < l; i++) {
		unsigned long long var = str[i] - 'a' + 1;
		for (int j = 0; j < i; j++)
			var = var * r % M;
		value = (value + var) % M;
	}
	return value;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int l;
	cin >> l;
	string str;
	cin >> str;
	cout << hashFunction(str, l);
}