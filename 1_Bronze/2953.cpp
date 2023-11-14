#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int maxScore = -1;
    int maxIdx = -1;
    for (int i = 1; i <= 5; i++) {
        int sum = 0;
        for (int j = 0; j < 4; j++) {
            int num;
            cin >> num;
            sum += num;
        }
        if (sum > maxScore) {
            maxScore = sum;
            maxIdx = i;
        }
    }
    cout << maxIdx << " " << maxScore;
}