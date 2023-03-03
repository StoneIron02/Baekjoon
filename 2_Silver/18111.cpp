#include <iostream>
#include <climits>

using namespace std;

int n, m, b;
int numHeight[257] {0};

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int h;
            cin >> h;
            numHeight[h]++;
        }
    }

    long long time = LLONG_MAX;
    int maxHeight = -1;

    for (int h = 0; h <= 256; h++) {
        // 현재 높이로 땅을 고를 때 필요한 블록의 개수
        int toPlace = 0, toBreak = 0;
        for (int i = 0; i <= 256; i++) {
            int sub = (h - i) * numHeight[i];
            if (sub > 0)
                toPlace += sub;
            else
                toBreak -= sub;
        }
        if (toPlace > b + toBreak) continue;

        // 시간 계산 후 max값 업데이트
        long long newTime = toPlace + toBreak * 2;
        if (newTime <= time) {
            time = newTime;
            maxHeight = h;
        }
    }

    cout << time << " " << maxHeight;
}