#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	while (true) {
		int n;
		cin >> n;
		if (n == 0)
			exit(0);

		map<string, string> origin;
		vector<string> words(n);
		for (int i = 0; i < n; i++) {
			string word;
			cin >> word;
			words[i] = word;
			for (int j = 0; j < words[i].size(); j++) {
				if (words[i][j] >= 'A' && words[i][j] <= 'Z')
					words[i][j] = words[i][j] - 'A' + 'a';
			}
			origin.insert({ words[i], word});
		}

		sort(words.begin(), words.end());
		cout << origin[words[0]] << "\n";
	}
}