#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct compare {
	bool operator()(pair<double, int> a, pair<double, int> b) {
		if (a.first == b.first)
			return a.second > b.second;
		return a.first < b.first;
	}
};

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	priority_queue<pair<double, int>, vector<pair<double, int>>, compare> pq;

	for (int i = 0; i < n; i++) {
		double w, h;
		cin >> w >> h;
		double ppi = sqrt(w * w + h * h) / 77;
		pq.push({ ppi, i + 1 });
	}

	while (!pq.empty()) {
		cout << pq.top().second << "\n";
		pq.pop();
	}
}