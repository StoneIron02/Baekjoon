#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, k;
int maxCount;
vector<string> words(50);
bool isTeached[27][26]{ 0 };

bool canRead(int cur, int i) {
	int length = words[i].size();
	for (int j = 0; j < length; j++) {
		if (!isTeached[cur][words[i][j] - 'a'])
			return false;
	}
	return true;
}

void backtracking(int cur, int before) {
	if (cur == k) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (canRead(cur, i))
				cnt++;
		}
		maxCount = cnt > maxCount ? cnt : maxCount;
	}

	for (int i = before + 1; i < 26; i++) {
		if (isTeached[cur][i]) continue;

		for (int j = 0; j < 26; j++) {
			isTeached[cur + 1][j] = isTeached[cur][j];
		}
		isTeached[cur + 1][i] = true;
		backtracking(cur + 1, i);
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> k;
	maxCount = 0;
	for (int i = 0; i < n; i++) {
		cin >> words[i];
	}
	if (k < 5) {
		cout << 0;
		exit(0);
	}
	isTeached[0]['a' - 'a'] = true;
	isTeached[0]['n' - 'a'] = true;
	isTeached[0]['t' - 'a'] = true;
	isTeached[0]['i' - 'a'] = true;
	isTeached[0]['c' - 'a'] = true;
	k -= 5;
	backtracking(0, -1);
	cout << maxCount;
}