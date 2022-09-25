#include <iostream>
#include <queue>
using namespace std;

long long greedy(priority_queue<long long, vector<long long>, greater<long long>>& pq) {
	long long sum = 1;
	long long div = 1000000007;
	while (pq.size() > 1) {
		long long a = pq.top(); pq.pop();
		long long b = pq.top(); pq.pop();
		long long c = a * b;
		pq.push(c);
		sum = c % div * sum % div;
	}
	return sum;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		priority_queue<long long, vector<long long>, greater<long long>> pq;
		for (int j = 0; j < n; j++) {
			long long num;
			cin >> num;
			pq.push(num);
		}
		cout << greedy(pq) << "\n";
	}
}