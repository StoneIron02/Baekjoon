#include <iostream>
using namespace std;

int main() {
	long long n, m;
	cin >> n >> m;
	long long num = n - m;
	if (num < 0)
		num = -num;
	cout << num;
}