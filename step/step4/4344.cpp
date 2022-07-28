#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

float getAve(int* score, int size) {
	float sum = 0;
	for (int i = 0; i < size; i++) {
		sum += score[i];
	}
	return sum / size;
}

int main() {
	int c;
	cin >> c;

	vector<int> students;
	vector<int*> scores;

	for (int i = 0; i < c; i++) {
		int n;
		cin >> n;
		cin.ignore(1, ' ');
		students.push_back(n);
		
		int* score = new int[n];
		for (int j = 0; j < n; j++) {
			cin >> score[j];
			cin.ignore(1, ' ');
		}
		scores.push_back(score);
	}

	for (int i = 0; i < c; i++) {
		float ave = getAve(scores[i], students[i]);

		float upAveStudents = 0;
		for (int j = 0; j < students[i]; j++) {
			if (scores[i][j] > ave)
				upAveStudents++;
		}

		cout << fixed << setprecision(3) << upAveStudents / students[i] * 100 << "%\n";
	}
}
