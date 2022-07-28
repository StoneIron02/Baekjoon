#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int getMax(vector<int> vec) {
	int max = 0;
	for (int i = 0; i < vec.size(); i++) {
		if (max < vec[i])
			max = vec[i];
	}
	return max;
}

int main() {
	int n;
	cin >> n;

	vector<int> scores;

	for (int i = 0; i < n; i++) {
		int score;
		cin >> score;
		scores.push_back(score);
		cin.ignore(1, ' ');
	}

	int max = getMax(scores);

	vector<float> newScores;

	for (int i = 0; i < n; i++) {
		newScores.push_back(((float)scores[i]) / max * 100);
	}

	float sum = 0;
	for (int i = 0; i < n; i++) {
		sum += newScores[i];
	}

	cout << setprecision(15) << sum / n;

}
