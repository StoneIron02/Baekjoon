#include <iostream>

using namespace std;

int parent[26];
int leftChild[26];
int rightChild[26];

void preOrder(int cur) {
    cout << (char)(cur + 'A');
    if (leftChild[cur] != -1) {
        preOrder(leftChild[cur]);
    }
    if (rightChild[cur] != -1) {
        preOrder(rightChild[cur]);
    }
}

void inOrder(int cur) {
    if (leftChild[cur] != -1) {
        inOrder(leftChild[cur]);
    }
    cout << (char)(cur + 'A');
    if (rightChild[cur] != -1) {
        inOrder(rightChild[cur]);
    }
}

void postOrder(int cur) {
    if (leftChild[cur] != -1) {
        postOrder(leftChild[cur]);
    }
    if (rightChild[cur] != -1) {
        postOrder(rightChild[cur]);
    }
    cout << (char)(cur + 'A');
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    for (int i = 0; i < 26; i++) {
        parent[i] = -1;
        leftChild[i] = -1;
        rightChild[i] = -1;
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char cur, l, r;
        cin >> cur >> l >> r;
        int curInt = cur - 'A';
        int lInt = l - 'A';
        int rInt = r - 'A';
        if (l != '.') {
            leftChild[curInt] = lInt;
            parent[lInt] = curInt;
        }
        if (r != '.') {
            rightChild[curInt] = rInt;
            parent[rInt] = curInt;
        }
    }

    preOrder(0);
    cout << "\n";
    inOrder(0);
    cout << "\n";
    postOrder(0);
    cout << "\n";
}