#include <iostream>
#include <string>
using namespace std;

struct node {
	char c;
	node* parent;
	node* left;
	node* right;
	node(char c, node* parent) : c(c), parent(parent) {
		left = nullptr;
		right = nullptr;
	}
};

node* recover_tree(string pre, string in, int preHash[], int inHash[], int start, int end, node* parent) {
	if (start == end - 1) {
		return new node(in[start], parent);
	}

	char minChar = in[start];
	for (int i = start + 1; i < end; i++)
		minChar = preHash[in[i] - 'A'] < preHash[minChar - 'A'] ? in[i] : minChar;

	int mid = inHash[minChar - 'A'];
	node* subroot = new node(minChar, parent);

	if (mid - start > 0)
		subroot->left = recover_tree(pre, in, preHash, inHash, start, mid, subroot);
	if (end - mid - 1 > 0)
		subroot->right = recover_tree(pre, in, preHash, inHash, mid + 1, end, subroot);

	return subroot;
}

void postOrder(node* root) {
	if (root->left != nullptr)
		postOrder(root->left);
	if (root->right != nullptr)
		postOrder(root->right);
	cout << root->c;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	while (true) {
		string pre, in;
		cin >> pre >> in;
		if (pre == "" || in == "")
			break;
		int preHash[26]{ 0 }, inHash[26]{ 0 };
		for (int i = 0; i < pre.size(); i++) {
			preHash[pre[i] - 'A'] = i;
			inHash[in[i] - 'A'] = i;
		}
		node* root = recover_tree(pre, in, preHash, inHash, 0, pre.size(), nullptr);
		postOrder(root);
		cout << "\n";
	}
}