#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n;
	cin >> n;
	priority_queue<int> factors;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		factors.push(num);
	}
	int max = factors.top();
	while (factors.size() > 1)
		factors.pop();
	int min = factors.top();
	cout << max * min;
}