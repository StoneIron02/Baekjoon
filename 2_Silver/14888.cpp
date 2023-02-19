#include <iostream>
#include <climits>

using namespace std;

int n;
int nums[11];
int numOperators[12][4];

long long maxResult = LLONG_MIN, minResult = LLONG_MAX;

void backtracking(int cur, long long result) {
    if (cur == n) {
        maxResult = result > maxResult ? result : maxResult;
        minResult = result < minResult ? result : minResult;
        return;
    }


    for (int i = 0; i < 4; i++) {
        if (numOperators[cur][i] == 0) continue;
        for (int j = 0; j < 4; j++)
            numOperators[cur + 1][j] = numOperators[cur][j];
        numOperators[cur + 1][i]--;
        if (i == 0) // +
            backtracking(cur + 1, result + nums[cur]);
        else if (i == 1) // -
            backtracking(cur + 1, result - nums[cur]);
        else if (i == 2) // *
            backtracking(cur + 1, result * nums[cur]);
        else if (i == 3) // /
            backtracking(cur + 1, result / nums[cur]);
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> numOperators[1][i];
    }

    backtracking(1, nums[0]);

    cout << maxResult << "\n";
    cout << minResult << "\n";
}