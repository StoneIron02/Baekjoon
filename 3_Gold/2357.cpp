#include <iostream>

using namespace std;

int n, m;
int arr[100'001];
int treeMin[400'001];
int treeMax[400'001];

void constructMin(int curNode, int start, int end) {
    if (start == end)
        treeMin[curNode] = arr[start];
    else {
        int mid = (start + end) / 2;
        constructMin(curNode * 2, start, mid);
        constructMin(curNode * 2 + 1, mid + 1, end);
        treeMin[curNode] = min(treeMin[curNode * 2], treeMin[curNode * 2 + 1]);
    }
}

void constructMax(int curNode, int start, int end) {
    if (start == end)
        treeMax[curNode] = arr[start];
    else {
        int mid = (start + end) / 2;
        constructMax(curNode * 2, start, mid);
        constructMax(curNode * 2 + 1, mid + 1, end);
        treeMax[curNode] = max(treeMax[curNode * 2], treeMax[curNode * 2 + 1]);
    }
}

long long queryMin(int curNode, int start, int end, int left, int right) {
    if (left > end || right < start)
        return INT32_MAX;
    if (left <= start && end <= right)
        return treeMin[curNode];
    int mid = (start + end) / 2;
    long long resultLeft = queryMin(curNode * 2, start, mid, left, right);
    long long resultRight = queryMin(curNode * 2 + 1, mid + 1, end, left, right);
    return min(resultLeft, resultRight);
}

long long queryMax(int curNode, int start, int end, int left, int right) {
    if (left > end || right < start)
        return -1;
    if (left <= start && end <= right)
        return treeMax[curNode];
    int mid = (start + end) / 2;
    long long resultLeft = queryMax(curNode * 2, start, mid, left, right);
    long long resultRight = queryMax(curNode * 2 + 1, mid + 1, end, left, right);
    return max(resultLeft, resultRight);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    constructMin(1, 1, n);
    constructMax(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        cout << queryMin(1, 1, n, a, b) << " " << queryMax(1, 1, n, a, b) << "\n";
    }
}