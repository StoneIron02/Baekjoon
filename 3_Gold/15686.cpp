#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<bool> curSelect;
int minCityDist = INT32_MAX;

void backtracking(int cur, int before) {
    if (cur == m) {
        int sum = 0;
        for (auto h : house) {
            int minDist = INT32_MAX;
            for (int i = 0; i < chicken.size(); i++) {
                if (!curSelect[i]) continue;
                minDist = min(minDist, abs(chicken[i].first - h.first) + abs(chicken[i].second - h.second));
            }
            sum += minDist;
        }
        minCityDist = min(minCityDist, sum);
        return;
    }
    for (int i = before; i < chicken.size(); i++) {
        if (curSelect[i]) continue;
        curSelect[i] = true;
        backtracking(cur + 1, i);
        curSelect[i] = false;
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int num;
            cin >> num;
            if (num == 1)
                house.emplace_back(i, j);
            if (num == 2)
                chicken.emplace_back(i, j);
        }
    }
    curSelect.resize(chicken.size());
    backtracking(0, 0);
    cout << minCityDist;
}