#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> matmul_single(vector<vector<long long>> a, vector<vector<long long>> b) {
    int n = a.size();
    vector<vector<long long>> result(n, vector<long long>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            long long sum = 0;
            for (int k = 0; k < n; k++) {
                sum += a[i][k] * b[k][j];
                sum %= 1'000'000'007;
            }
            result[i][j] = sum % 1'000'000'007;
        }
    }
    return result;
}

vector<vector<long long>> matmul(long long n) {
    if (n == 1) {
        vector<vector<long long>> result = {{1, 1}, {1, 0}};
        return result;
    }

    auto before = matmul(n / 2);
    auto after = matmul_single(before, before);

    if (n % 2 == 0) {
        return after;
    }
    else {
        vector<vector<long long>> a = {{1, 1}, {1, 0}};
        auto final = matmul_single(after, a);
        return final;
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    long long n;
    cin >> n;

    if (n == 1) {
        cout << 1;
        return 0;
    }

    auto result = matmul(n - 1);
    cout << result[0][0];
}