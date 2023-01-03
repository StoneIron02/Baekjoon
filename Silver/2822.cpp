#include <iostream>
#include <queue>
#include <set>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	priority_queue<pair<int, int>> scores;
	for (int i = 0; i < 8; i++) {
		int num;
		cin >> num;
		scores.push({ num, i + 1 });
	}

	int sum = 0;
	set<int> indexes;
	for (int i = 0; i < 5; i++) {
		pair<int, int> score = scores.top();
		scores.pop();
		sum += score.first;
		indexes.insert(score.second);
	}

	cout << sum << "\n";
	for (int i : indexes)
		cout << i << " ";
}