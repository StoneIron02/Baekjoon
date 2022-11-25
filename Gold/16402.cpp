#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<pair<string, int>> kingdom;
map<string, int> hashdata;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	cin.get();
	kingdom.resize(n + 1);
	int cnt = n;
	for (int i = 1; i <= n; i++) {
		string str;
		getline(cin, str);
		hashdata.insert({ str, i });
		kingdom[i] = { str, 0 };
	}
	for (int i = 0; i < m; i++) {
		string str;
		getline(cin, str, ',');
		int kingdom1 = hashdata[str];
		int parent1 = kingdom1;
		while (kingdom[parent1].second != 0)
			parent1 = kingdom[parent1].second;
		getline(cin, str, ',');
		int kingdom2 = hashdata[str];
		int parent2 = kingdom2;
		while (kingdom[parent2].second != 0)
			parent2 = kingdom[parent2].second;
		int whowin;
		cin >> whowin;

		if (parent1 == parent2) {
			if (kingdom[kingdom2].second == 0 && whowin == 1) {
				kingdom[kingdom2].second = kingdom1;
				kingdom[kingdom1].second = 0;
			}
			else if (kingdom[kingdom1].second == 0 && whowin == 2) {
				kingdom[kingdom1].second = kingdom2;
				kingdom[kingdom2].second = 0;
			}
		}
		else {
			if (whowin == 1) {
				kingdom[parent2].second = parent1;
				cnt--;
			}
			else {
				kingdom[parent1].second = parent2;
				cnt--;
			}
		}
		cin.get();
	}
	cout << cnt << "\n";
	for (pair<string, int> data : hashdata) {
		if (kingdom[data.second].second == 0)
			cout << data.first << "\n";
	}
}