#include <iostream>

using namespace std;

int n, m, k;
int arr[1'000'001];
int tree[4'000'001];

#define MOD 1'000'000'007

void construct(int curNode, int start, int end) {
    if (start == end)
        tree[curNode] = arr[start];
    else {
        int mid = (start + end) / 2;
        construct(curNode * 2, start, mid);
        construct(curNode * 2 + 1, mid + 1, end);
        tree[curNode] = 1LL * tree[curNode * 2] * tree[curNode * 2 + 1] % MOD;
    }
}

int query(int curNode, int start, int end, int left, int right) {
    if (left > end || right < start)
        return 1;
    if (left <= start && end <= right)
        return tree[curNode];
    int mid = (start + end) / 2;
    int resultLeft = query(curNode * 2, start, mid, left, right);
    int resultRight = query(curNode * 2 + 1, mid + 1, end, left, right);
    return 1LL * resultLeft * resultRight % MOD;
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
    tree[curNode] = 1LL * tree[curNode * 2] * tree[curNode * 2 + 1] % MOD;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    construct(1, 1, n);
    for (int i = 1; i <= m + k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            update(1, 1, n, b, c);
        } else if (a == 2) {
            cout << query(1, 1, n, b, c) << "\n";
        }
    }
}