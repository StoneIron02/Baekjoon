#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int n;
map<string, int> score;

bool compare(pair<string, int> c1, pair<string, int> c2) {
	if (c1.second == c2.second)
		return c1.first < c2.first;
	return c1.second > c2.second;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		score[str] = 0;
	}
	cin.get();
	for (int i = 0; i < n; i++) {
		string str;
		getline(cin, str);
		int start = 0;
		int end;
		while ((end = str.find(' ', start)) != -1) {
			string name = str.substr(start, end - start);
			score[name]++;
			start = end + 1;
		}
		string name = str.substr(start);
		score[name]++;
	}
	vector<pair<string, int>> vec(score.begin(), score.end());
	sort(vec.begin(), vec.end(), compare);
	for (pair<string, int> cur : vec) {
		cout << cur.first << " " << cur.second << "\n";
	}
}