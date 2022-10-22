#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	vector<int> vec;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int line;
		cin >> line;
		vec.insert(vec.begin() + line, i + 1);
	}
	for (int i = vec.size() - 1; i >= 0; i--) {
		cout << vec[i] << " ";
	}
}