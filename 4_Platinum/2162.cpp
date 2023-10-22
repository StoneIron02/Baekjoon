#include <iostream>
#include <map>

using namespace std;

int n;
pair<pair<int, int>, pair<int, int>> lines[3000];
int parent[3000];

void init() {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
}

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX < rootY) {
        parent[rootY] = rootX;
    } else {
        parent[rootX] = rootY;
    }
}

int ccw(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
    long long crossProduct = 1LL * (p2.first - p1.first) * (p3.second - p1.second) -
            1LL * (p2.second - p1.second) * (p3.first - p1.first);
    if (crossProduct > 0) return 1;  // 시계 방향
    if (crossProduct < 0) return -1; // 반시계 방향
    return 0; // 평행
}

bool isIntersect(int a, int b) {
    pair<int, int>& p1 = lines[a].first;
    pair<int, int>& p2 = lines[a].second;
    pair<int, int>& p3 = lines[b].first;
    pair<int, int>& p4 = lines[b].second;

    int ccw1 = ccw(p1, p2, p3);
    int ccw2 = ccw(p1, p2, p4);
    int ccw3 = ccw(p3, p4, p1);
    int ccw4 = ccw(p3, p4, p2);

    if (ccw1 * ccw2 > 0 || ccw3 * ccw4 > 0) {
        return false;
    }
    else if (ccw1 * ccw2 == 0 && ccw3 * ccw4 == 0) {
        if (p1 > p2) swap(p1, p2);
        if (p3 > p4) swap(p3, p4);
        if (p3 <= p2 && p1 <= p4)
            return true;
        else
            return false;
    }
    return true;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        lines[i] = {{x1, y1}, {x2, y2}};
    }
    init();

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (i == j) continue;
            if (isIntersect(i, j)) {
                unionSets(i, j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        find(i);
    }

    map<int, int> result;
    int maxCnt = -1;
    for (int i = 0; i < n; i++) {
        int p = find(i);
        result[p]++;
        maxCnt = max(maxCnt, result[p]);
    }
    cout << result.size() << "\n";
    cout << maxCnt;
}