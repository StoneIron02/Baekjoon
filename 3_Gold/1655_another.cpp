#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> min;
	priority_queue<int, vector<int>, less<int>> max;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (min.empty() && max.empty()) {
			max.push(num);
			cout << max.top() << "\n";
		}
		else if (min.empty()) {
			max.push(num);
			min.push(max.top());
			max.pop();
			cout << max.top() << "\n";
		}
		else {
			if (num < min.top())
				max.push(num);
			else
				min.push(num);

			while (((int)min.size() - (int)max.size()) > 0) {
				max.push(min.top());
				min.pop();
			}
			while (((int)max.size() - (int)min.size()) > 1) {
				min.push(max.top());
				max.pop();
			}
			
			cout << max.top() << "\n";
		}
	}
}