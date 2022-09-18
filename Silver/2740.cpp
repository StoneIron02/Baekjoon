#include <iostream>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	int** matrix1 = new int* [n];
	for (int i = 0; i < n; i++) {
		matrix1[i] = new int[m];
		for (int j = 0; j < m; j++) {
			cin >> matrix1[i][j];
		}
	}

	int k;
	cin >> m >> k;
	int** matrix2 = new int* [m];
	for (int i = 0; i < m; i++) {
		matrix2[i] = new int[k];
		for (int j = 0; j < k; j++) {
			cin >> matrix2[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			int sum = 0;
			for (int index = 0; index < m; index++) {
				sum += matrix1[i][index] * matrix2[index][j];
			}
			cout << sum << " ";
		}
		cout << "\n";
	}
}