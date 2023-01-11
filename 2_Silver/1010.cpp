#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> table;

int binomial_coefficient(int n, int k) {
	for (int i = 0; i <= n; i++) {
		table.push_back(vector<int>());
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) {
				table[i].push_back(1);
			}
			else {
				table[i].push_back((table[i - 1][j - 1] + table[i - 1][j]));
			}
		}
	}
	return table[n][k];
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, m;
		cin >> n >> m;
		cout << binomial_coefficient(m, n) << "\n";
	}
}