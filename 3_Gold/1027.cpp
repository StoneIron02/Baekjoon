#include <iostream>

using namespace std;

int n;
long long building[51];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> building[i];

    int maxSeeCnt = -1;
    for (int i = 1; i <= n; i++) {
        int canSeeCnt = 0;
        int leftIndex = 0, rightIndex = 0;
        for (int j = i - 1; j >= 1; j--) {
            if (j == i - 1) {
                canSeeCnt++;
                leftIndex = j;
                continue;
            }
            // gradient = dy_ij / dx_ij < maxGradient = dy_ileft / dx_ileft
            long long dy_ij = building[i] - building[j];
            long long dy_ileft = building[i] - building[leftIndex];
            long long dx_ij = i - j;
            long long dx_ileft = i - leftIndex;

            if (dy_ij * dx_ileft < dy_ileft * dx_ij) {
                canSeeCnt++;
                leftIndex = j;
            }
        }
        for (int j = i + 1; j <= n; j++) {
            if (j == i + 1) {
                canSeeCnt++;
                rightIndex = j;
                continue;
            }
            // gradient = dy_ij / dx_ij > maxGradient = dy_iright / dx_iright
            long long dy_ij = building[i] - building[j];
            long long dy_iright = building[i] - building[rightIndex];
            long long dx_ij = i - j;
            long long dx_iright = i - rightIndex;

            if (dy_ij * dx_iright > dy_iright * dx_ij) {
                canSeeCnt++;
                rightIndex = j;
            }
        }
        maxSeeCnt = canSeeCnt > maxSeeCnt ? canSeeCnt : maxSeeCnt;
    }

    cout << maxSeeCnt;
}