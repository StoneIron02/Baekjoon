#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    if (n == 0) {
        cout << 0;
        return 0;
    }

    int score[300000];
    for (int i = 0; i < n; i++)
        cin >> score[i];
    sort(score, score + n);

    int cut = round(n * 0.15);
    int sum = 0;
    for (int i = cut; i < n - cut; i++) {
        sum += score[i];
    }
    int avg = round((double)sum / (n - cut - cut));
    cout << avg;
}