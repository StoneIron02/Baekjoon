#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> combination;
vector<vector<int>> score;

int minDiffer = 100;

void cal(int n) {
	do {
		vector<int> team1, team2;
		int sumTeam1 = 0, sumTeam2 = 0;

		team2.push_back(0);
		for (int i = 0; i < n - 1; i++) {
			if (combination[i] == 1) {
				team1.push_back(i + 1);
			}
			else {
				team2.push_back(i + 1);
			}
		}

		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				if (i == j) continue;
				sumTeam1 += score[team1[i]][team1[j]];
				sumTeam2 += score[team2[i]][team2[j]];
			}
		}

		int differ = abs(sumTeam1 - sumTeam2);
		minDiffer = (minDiffer > differ ? differ : minDiffer);
		
	} while (next_permutation(combination.begin(), combination.end()));
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		score.push_back(vector<int>());
		for (int j = 0; j < n; j++) {
			int num;
			cin >> num;
			score[i].push_back(num);
		}
	}
	for (int i = 0; i < n / 2 - 1; i++) {
		combination.push_back(0);
	}
	for (int i = 0; i < n / 2; i++) {
		combination.push_back(1);
	}
	cal(n);
	cout << minDiffer;
}