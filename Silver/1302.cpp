#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool comp(pair<string, int> left, pair<string, int> right) {
	if (left.second == right.second)
		return left.first < right.first;
	return left.second > right.second;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;
	map<string, int> map;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		if (map.find(str) != map.end())
			map[str]++;
		else
			map[str] = 1;
	}
	vector<pair<string, int>> v;
	for (pair<string, int> data : map)
		v.push_back({ data.first, data.second });

	sort(v.begin(), v.end(), comp);
	cout << v[0].first;
}