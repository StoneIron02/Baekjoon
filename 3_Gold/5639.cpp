#include <iostream>

using namespace std;

int arr[10000];
int len = 0;
int idx = 1;

void BST(int start, int end, int cur) {
    if (idx < len && arr[idx] >= start && arr[idx] < end && arr[idx] < cur) {
        BST(start, cur, arr[idx++]);
    }
    if (idx < len && arr[idx] >= start && arr[idx] < end && arr[idx] > cur) {
        BST(cur + 1, end, arr[idx++]);
    }
    cout << cur << "\n";
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int num;
    while (cin >> num) {
        arr[len++] = num;
    }
    BST(1, 1000000, arr[0]);
}