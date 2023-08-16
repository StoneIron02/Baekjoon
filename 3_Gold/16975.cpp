#include <iostream>

using namespace std;

int n, m;
long long arr[100'001];
long long tree[400'001];
long long lazy[400'001];

void construct(int curNode, int start, int end) {
    if (start == end)
        tree[curNode] = arr[start];
    else {
        int mid = (start + end) / 2;
        construct(curNode * 2, start, mid);
        construct(curNode * 2 + 1, mid + 1, end);
        tree[curNode] = tree[curNode * 2] + tree[curNode * 2 + 1];
    }
}

void update_lazy(int curNode, int start, int end) {
    if (lazy[curNode] != 0) {
        tree[curNode] += (end - start + 1) * lazy[curNode];
        if (start != end) {
            lazy[curNode * 2] += lazy[curNode];
            lazy[curNode * 2 + 1] += lazy[curNode];
        }
        lazy[curNode] = 0;
    }
}

long long query(int curNode, int start, int end, int left, int right) {
    update_lazy(curNode, start, end);
    if (left > end || right < start)
        return 0;
    if (left <= start && end <= right)
        return tree[curNode];
    int mid = (start + end) / 2;
    long long resultLeft = query(curNode * 2, start, mid, left, right);
    long long resultRight = query(curNode * 2 + 1, mid + 1, end, left, right);
    return resultLeft + resultRight;
}

void update_range(int curNode, int start, int end, int left, int right, int diff) {
    update_lazy(curNode, start, end);
    if (left > end || right < start)
        return;
    if (left <= start && end <= right) {
        tree[curNode] += (end - start + 1) * diff;
        if (start != end) {
            lazy[curNode * 2] += diff;
            lazy[curNode * 2 + 1] += diff;
        }
        return;
    }
    int mid = (start + end) / 2;
    update_range(curNode * 2, start, mid, left, right, diff);
    update_range(curNode * 2 + 1, mid + 1, end, left, right, diff);
    tree[curNode] = tree[curNode * 2] + tree[curNode * 2 + 1];
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
        int a, b, c, d;
        cin >> a;
        if (a == 1) {
            cin >> b >> c >> d;
            update_range(1, 1, n, b, c, d);
        } else {
            cin >> b;
            cout << query(1, 1, n, b, b) << "\n";
        }
    }
}