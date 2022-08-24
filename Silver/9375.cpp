#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		map<string, int> counts;
		for (int j = 0; j < n; j++) {
			string name, key;
			cin >> name >> key;
			if (counts.find(key) != counts.end())
				counts.find(key)->second++;
			counts.insert({ key, 1 });
		}

		int result = 1;
		for (auto i : counts) {
			result *= (i.second + 1);
		}
		cout << (result - 1) << "\n";
	}
}