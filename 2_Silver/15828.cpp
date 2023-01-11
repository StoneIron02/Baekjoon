#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;
	queue<int> queue;
	while (true) {
		int num;
		cin >> num;
		if (num == -1) break;

		if (num == 0) queue.pop();
		else {
			if (queue.size() < n)
				queue.push(num);
		}
	}

	if (queue.size() == 0) {
		cout << "empty";
		exit(0);
	}
	while (queue.size() > 0) {
		cout << queue.front() << " ";
		queue.pop();
	}
}