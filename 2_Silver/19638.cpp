#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n, h, t;
	cin >> n >> h >> t;
	priority_queue<int> pq;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		pq.push(num);
	}

	int i;
	for (i = 0; i < t; i++) {
		if (pq.top() < h)
			break;

		int num = pq.top(); pq.pop();
		if (num == 1)
			pq.push(num);
		else
			pq.push(num / 2);
	}

	if (pq.top() < h)
		cout << "YES\n" << i;
	else
		cout << "NO\n" << pq.top();
}