#include <iostream>

using namespace std;

int arr[50'000];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int i = 0, j = 0;
    int maxCnt = 0;
    int curCnt = 0;
    while (j <= n - 1) {
        if (arr[j] % 2 == 0) {
            j++;
            curCnt++;
            maxCnt = max(maxCnt, curCnt);
        } else {
            if (k > 0) {
                j++;
                k--;
                maxCnt = max(maxCnt, curCnt);
            } else {
                if (arr[i] % 2 == 1) {
                    k++;
                } else {
                    curCnt--;
                }
                i++;
            }
        }
    }

    cout << maxCnt;
}