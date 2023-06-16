#include <iostream>

using namespace std;

int n;
int inorder[100'000];
int postorder[100'000];

void preorder(int instart, int inend, int poststart, int postend) {
    if (poststart == postend) return;
    int root_post = postorder[postend - 1];
    cout << root_post << " ";
    int root_in;
    for (root_in = instart; root_in < inend; root_in++) {
        if (inorder[root_in] == root_post) break;
    }
    int leftSize = root_in - instart;
    int rightSize = inend - root_in - 1;
    preorder(instart, root_in, poststart, poststart + leftSize);
    preorder(root_in + 1, inend, poststart + leftSize, poststart + leftSize + rightSize);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> inorder[i];
    for (int i = 0; i < n; i++)
        cin >> postorder[i];

    preorder(0, n, 0, n);
}