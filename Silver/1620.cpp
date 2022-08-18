#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	map<int, string> mapNum;
	map<string, int> mapName;
	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		mapNum.insert(pair<int, string>(i, str));
		mapName.insert(pair<string, int>(str, i));
	}
	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		try {
			int num = stoi(str);
			cout << mapNum.find(num)->second << "\n";
		}
		catch (invalid_argument) {
			cout << mapName.find(str)->second << "\n";
		}
	}
}