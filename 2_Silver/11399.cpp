#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int greedy(vector<int>& p) {
	sort(p.begin(), p.end());
	int sum = 0;
	int prev = 0;
	for (int time : p) {
		prev += time;
		sum += prev;
	}
	return sum;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> p(n);
	for (int i = 0; i < n; i++)
		cin >> p[i];
	cout << greedy(p);
}