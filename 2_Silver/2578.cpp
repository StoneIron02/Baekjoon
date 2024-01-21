#include <iostream>
#include <map>

using namespace std;

bool visit[5][5];
map<int, pair<int, int>> nums;

int check() {
    int cnt = 0;
    for (int i = 0; i < 5; i++) {
        bool flag = true;
        for (int j = 0; j < 5; j++) {
            if (!visit[i][j]) {
                flag = false;
            }
        }
        if (flag) {
            cnt++;
        }
    }
    for (int i = 0; i < 5; i++) {
        bool flag = true;
        for (int j = 0; j < 5; j++) {
            if (!visit[j][i]) {
                flag = false;
            }
        }
        if (flag) {
            cnt++;
        }
    }
    bool flag1 = true;
    for (int i = 0; i < 5; i++) {
        if (!visit[i][i]) {
            flag1 = false;
        }
    }
    if (flag1) {
        cnt++;
    }
    bool flag2 = true;
    for (int i = 0; i < 5; i++) {
        if (!visit[i][4 - i]) {
            flag2 = false;
        }
    }
    if (flag2) {
        cnt++;
    }
    return cnt;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int num;
            cin >> num;
            nums.insert({num, {i, j}});
        }
    }
    for (int i = 0; i < 25; i++) {
        int num;
        cin >> num;
        auto& [a, b] = nums[num];
        visit[a][b] = true;
        if (check() >= 3) {
            cout << (i + 1);
            break;
        }
    }
}