#include <iostream>

using namespace std;

int n, m;
int arr[500'001];
int tree[2'000'001];
int lazy[2'000'001];

void construct(int curNode, int start, int end) {
    if (start == end)
        tree[curNode] = arr[start];
    else {
        int mid = (start + end) / 2;
        construct(curNode * 2, start, mid);
        construct(curNode * 2 + 1, mid + 1, end);
        tree[curNode] = tree[curNode * 2] ^ tree[curNode * 2 + 1];
    }
}

void update_lazy(int curNode, int start, int end) {
    if (lazy[curNode] != 0) {
        tree[curNode] ^= (end - start + 1) % 2 * lazy[curNode];
        if (start != end) {
            lazy[curNode * 2] ^= lazy[curNode];
            lazy[curNode * 2 + 1] ^= lazy[curNode];
        }
        lazy[curNode] = 0;
    }
}

int query(int curNode, int start, int end, int left, int right) {
    update_lazy(curNode, start, end);
    if (left > end || right < start)
        return 0;
    if (left <= start && end <= right)
        return tree[curNode];
    int mid = (start + end) / 2;
    int resultLeft = query(curNode * 2, start, mid, left, right);
    int resultRight = query(curNode * 2 + 1, mid + 1, end, left, right);
    return resultLeft ^ resultRight;
}

void update_range(int curNode, int start, int end, int left, int right, int diff) {
    update_lazy(curNode, start, end);
    if (left > end || right < start)
        return;
    if (left <= start && end <= right) {
        tree[curNode] ^= (end - start + 1) % 2 * diff;
        if (start != end) {
            lazy[curNode * 2] ^= diff;
            lazy[curNode * 2 + 1] ^= diff;
        }
        return;
    }
    int mid = (start + end) / 2;
    update_range(curNode * 2, start, mid, left, right, diff);
    update_range(curNode * 2 + 1, mid + 1, end, left, right, diff);
    tree[curNode] = tree[curNode * 2] ^ tree[curNode * 2 + 1];
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
    for (int q = 1; q <= m; q++) {
        int f, i, j, k;
        cin >> f;
        if (f == 1) {
            cin >> i >> j >> k;
            update_range(1, 1, n, i + 1, j + 1, k);
        } else {
            cin >> i >> j;
            cout << query(1, 1, n, i + 1, j + 1) << "\n";
        }
    }
}