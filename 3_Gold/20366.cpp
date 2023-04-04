#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<long long> length(n);
    for (int i = 0; i < n; i++)
        cin >> length[i];

    sort(length.begin(), length.end());

    long long min = LLONG_MAX;
    // 왼쪽 범위, 눈덩이 1 선택
    for (int i = 0; i <= n - 4; i++) {
        // 오른쪽 범위, 눈덩이 1 선택
        for (int j = i + 3; j <= n - 1; j++) {
            // i, j의 눈덩이를 하나의 눈사람으로 선택
            long long snow1 = length[i] + length[j];

            // 투 포인터를 이용하여 두 번째 눈덩이 선택
            int k = i + 1, l = j - 1;
            while (k < l) {
                long long snow2 = length[k] + length[l];
                min = abs(snow1 - snow2) < min ? abs(snow1 - snow2) : min;

                if (snow1 > snow2) // 눈덩이 2를 키워야 함
                    k++;
                else if (snow1 < snow2) // 눈덩이 2를 줄여야 함
                    l--;
                else { // (snow1 == snow2)
                    cout << 0;
                    exit(0);
                }
            }
        }
    }

    cout << min;
}