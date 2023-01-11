#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	stack<int> coins;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		coins.push(num);
	}

	int count = 0;
	while (k > 0) {
		int coin = coins.top();
		count += k / coin;
		k %= coin;
		coins.pop();
	}
	cout << count;
}