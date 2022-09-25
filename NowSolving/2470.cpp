#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void find(vector<int>& v) {
	sort(v.begin(), v.end());
	int i = 0;
	int j = v.size() - 1;
	while (j - i > 1) {
		int now = abs(v[i] + v[j]);
		int ipp = abs(v[i + 1] + v[j]);
		int jmm = abs(v[i] + v[j - 1]);
		int pm = abs(v[i + 1] + v[j - 1]);

		int min = now;
		min = (min > ipp ? ipp : min);
		min = (min > jmm ? jmm : min);
		if (j - i > 2)
			min = (min > pm ? pm : min);
		if (min == now)
			break;
		else if (min == ipp)
			i++;
		else if (min == jmm)
			j--;
		else {
			i++;
			j--;
		}
	}
	cout << v[i] << " " << v[j];
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