#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;
vector<int> A(500000);
vector<int> tmp(500000);

void merge(int p, int q, int r, int k) {
    int i = p, j = q + 1, t = 0;
    while (i <= q && j <= r) {
        if (A[i] <= A[j])
            tmp[t++] = A[i++];
        else tmp[t++] = A[j++];
    }
    while (i <= q)
        tmp[t++] = A[i++];
    while (j <= r)
        tmp[t++] = A[j++];
    i = p;
    t = 0;
    while (i <= r) {
        A[i++] = tmp[t++];
        cnt++;
        if (cnt == k)
            cout << A[i - 1];
    }
}

void merge_sort(int p, int r, int k) {
    if (p < r) {
        int q = (p + r) / 2;
        merge_sort( p, q, k);
        merge_sort(q + 1, r, k);
        merge(p, q, r, k);
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    merge_sort(0, n - 1, k);
    if (cnt < k)
        cout << "-1";
}