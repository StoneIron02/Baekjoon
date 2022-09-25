#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void find(vector<int>& v) {
	sort(v.begin(), v.end());
	int i = 0, j = v.size() - 1;
	int minI = i, minJ = j;
	while (i < j) {
		if (abs(v[i] + v[j]) < abs(v[minI] + v[minJ])) {
			minI = i;
			minJ = j;
		}

		if (v[i] + v[j] >= 0) // +, 0
			j--;
		else // -
			i++;
	}
	cout << v[minI] << " " << v[minJ];
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	find(v);
}