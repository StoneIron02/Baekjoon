#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int r, c, k;
int curR = 3, curC = 3;
int arr[100][100] {0};

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> r >> c >> k;
    for (int i = 0; i < curR; i++) {
        for (int j = 0; j < curC; j++) {
            cin >> arr[i][j];
        }
    }

    for (int timer = 0; timer <= 100; timer++) {
        if (arr[r - 1][c - 1] == k) {
            cout << timer;
            exit(0);
        }

        if (curR >= curC) { // 행에 대하여 수행
            int reC = 0;
            for (int i = 0; i < 100; i++) {
                int cnt[101] {0};
                for (int j = 0; j < 100; j++) {
                    int num = arr[i][j];
                    cnt[num]++;
                }
                vector<pair<int, int>> rev;
                for (int j = 1; j <= 100; j++) {
                    if (cnt[j] > 0)
                        rev.emplace_back(cnt[j], j);
                }
                sort(rev.begin(), rev.end());
                if (rev.size() > 50)
                    rev.resize(50);
                reC = rev.size() * 2 > reC ? rev.size() * 2 : reC;
                int j = 0;
                for (pair<int, int>& data : rev) {
                    arr[i][j++] = data.second;
                    arr[i][j++] = data.first;
                }
                for (; j < 100; j++) {
                    arr[i][j] = 0;
                }
            }
            curC = reC;
        } else { // 열에 대하여 수행
            int reR = 0;
            for (int j = 0; j < 100; j++) {
                int cnt[101] {0};
                for (int i = 0; i < 100; i++) {
                    int num = arr[i][j];
                    cnt[num]++;
                }
                vector<pair<int, int>> rev;
                for (int i = 1; i <= 100; i++) {
                    if (cnt[i] > 0)
                        rev.emplace_back(cnt[i], i);
                }
                sort(rev.begin(), rev.end());
                if (rev.size() > 50)
                    rev.resize(50);
                reR = rev.size() * 2 > reR ? rev.size() * 2 : reR;
                int i = 0;
                for (pair<int, int>& data : rev) {
                    arr[i++][j] = data.second;
                    arr[i++][j] = data.first;
                }
                for (; i < 100; i++) {
                    arr[i][j] = 0;
                }
            }
            curR = reR;
        }
    }
    cout << -1;
}