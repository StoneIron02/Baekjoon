#include <iostream>
#include <vector>
using namespace std;

int n;
int root;
int parent[50];
vector<int> childs[50];

int preOrder(int curNode) {
    if (childs[curNode].empty())
        return 1;

    int result = 0;
    for (int child : childs[curNode])
        result += preOrder(child);
    return result;
}

int main() {
	cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> parent[i];
        if (parent[i] == -1)
            root = i;
        else
            childs[parent[i]].push_back(i);
    }

    int remove;
    cin >> remove;
    if (remove == root) {
        cout << 0;
        exit(0);
    }
    int removeParent = parent[remove];
    for (int i = 0; i < childs[removeParent].size(); i++) {
        if (childs[removeParent][i] == remove) {
            childs[removeParent].erase(childs[removeParent].begin() + i);
            break;
        }
    }

    cout << preOrder(root);
}