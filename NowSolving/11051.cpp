#include <iostream>
using namespace std;

int main() {
	int k, n;
	cin >> n >> k;

	long combination = 1;
	for (int i = 1; i <= k; i++) {
		combination *= n - k + 1;
		combination /= i;
	}

	cout << combination;
}