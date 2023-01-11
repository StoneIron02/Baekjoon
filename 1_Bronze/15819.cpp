#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n, i;
	cin >> n >> i;
	vector<string> vector(n);
	for (int i = 0; i < n; i++) {
		cin >> vector[i];
	}

	sort(vector.begin(), vector.end());

	cout << vector[i - 1];
}