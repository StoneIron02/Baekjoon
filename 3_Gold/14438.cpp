#include <iostream>

using namespace std;

int n, m;
int arr[100'001];
int tree[400'001];

void construct(int curNode, int start, int end) {
    if (start == end)
        tree[curNode] = arr[start];
    else {
        int mid = (start + end) / 2;
        construct(curNode * 2, start, mid);
        construct(curNode * 2 + 1, mid + 1, end);
        tree[curNode] = min(tree[curNode * 2], tree[curNode * 2 + 1]);
    }
}

long long query(int curNode, int start, int end, int left, int right) {
    if (left > end || right < start)
        return INT32_MAX;
    if (left <= start && end <= right)
        return tree[curNode];
    int mid = (start + end) / 2;
    long long resultLeft = query(curNode * 2, start, mid, left, right);
    long long resultRight = query(curNode * 2 + 1, mid + 1, end, left, right);
    return min(resultLeft, resultRight);
}

void update(int curNode, int start, int end, int index, int val) {
    if (index < start || index > end)
        return;
    if (start == end) {
        arr[index] = val;
        tree[curNode] = val;
        return;
    }
    int mid = (start + end) / 2;
    update(curNode * 2, start, mid, index, val);
    update(curNode * 2 + 1, mid + 1, end, index, val);
    tree[curNode] = min(tree[curNode * 2], tree[curNode * 2 + 1]);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    construct(1, 1, n);
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            update(1, 1, n, b, c);
        } else if (a == 2) {
            cout << query(1, 1, n, b, c) << "\n";
        }
    }
}