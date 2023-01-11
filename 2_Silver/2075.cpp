#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<>> queue;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		queue.push(num);
	}
	for (int i = n; i < n * n; i++) {
		int num;
		cin >> num;
		queue.push(num);
		queue.pop();
	}
	cout << queue.top();
}