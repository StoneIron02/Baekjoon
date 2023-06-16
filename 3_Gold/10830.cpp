#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> matrix_mul_single(vector<vector<int>> a, vector<vector<int>> b) {
    int n = a.size();
    vector<vector<int>> result(n);
    for (int i = 0; i < n; i++) {
        result[i].resize(n);
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++) {
                sum += a[i][k] * b[k][j];
            }
            result[i][j] = sum % 1000;
        }
    }
    return result;
}

vector<vector<int>> matrix_mul(vector<vector<int>> matrix, long long b) {
    if (b == 1) {
        return matrix;
    }

    auto before = matrix_mul(matrix, b / 2);
    auto after = matrix_mul_single(before, before);

    if (b % 2 == 0) {
        return after;
    }
    else {
        auto final = matrix_mul_single(after, matrix);
        return final;
    }
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

    int n;
    long long b;
    cin >> n >> b;
    vector<vector<int>> matrix(n);
    for (int i = 0; i < n; i++) {
        matrix[i].resize(n);
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
            matrix[i][j] %= 1000;
        }
    }

    auto result = matrix_mul(matrix, b);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
}