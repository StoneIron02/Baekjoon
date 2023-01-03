#include <iostream>
#include <vector>
using namespace std;

unsigned int n;
unsigned int newScore;
unsigned int p;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> newScore >> p;
	vector<unsigned int> scores(n);
	for (int i = 0; i < n; i++) {
		cin >> scores[i];
	}
	int index;
	int sameIndex = 0;
	for (index = 0; index < n; index++) {
		if (newScore < scores[index]) sameIndex++;
		if (newScore > scores[index]) break;
	}

	if (index == p)
		cout << -1;
	else
		cout << sameIndex + 1;
}