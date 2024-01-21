#include <iostream>

using namespace std;

int n;
int cnt = 0;
string result;

void backtracking(int cur, int k) {
    if (cur == k) {
        cnt++;
        if (n == cnt) {
            cout << result;
            exit(0);
        }
    }

    for (int i = 0; i <= 9; i++) {
        if (!result.empty() && result[result.size() - 1] - '0' <= i) continue;
        result += to_string(i);
        backtracking(cur + 1, k);
        result = result.substr(0, result.size() - 1);
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= 15; i++) {
        backtracking(0, i);
    }
    cout << -1;
}