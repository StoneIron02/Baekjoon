#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	set<int> set;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		set.insert(num);
	}

	for (int num : set) {
		cout << num << " ";
	}
}