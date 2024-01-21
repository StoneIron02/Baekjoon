#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int maxScore = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, d, g;
        cin >> a >> d >> g;
        int score = a * (d + g);
        if (a == d + g)
            score *= 2;
        maxScore = max(maxScore, score);
    }
    cout << maxScore;
}