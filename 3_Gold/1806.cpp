#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, s;
    cin >> n >> s;
    int sum[n + 1];
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        sum[i] = sum[i - 1] + num;
    }

    int minNum = INT32_MAX;
    int i = 1;
    int j = 1;
    while (i <= j && j <= n) {
        int curSum = sum[j] - sum[i - 1];
        if (curSum >= s) {
            minNum = min(minNum, j - i + 1);
            i++;
        } else {
            j++;
        }
    }
    if (minNum == INT32_MAX)
        minNum = 0;
    cout << minNum;
}