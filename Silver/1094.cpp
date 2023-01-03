#include <iostream>
#include <queue>
using namespace std;

int x;
priority_queue<int, vector<int>, greater<int>> sticks;
int sum = 64;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> x;
	sticks.push(64);

	while (x < sum) {
		int curSticks = sticks.top();
		sticks.pop();
		int halfSticks = curSticks / 2;
		if (x <= sum - halfSticks) {
			sum -= halfSticks;
			sticks.push(halfSticks);
		}
		else {
			sticks.push(halfSticks);
			sticks.push(halfSticks);
		}
	}
	cout << sticks.size();
}