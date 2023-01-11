#include <iostream>
#include <vector>
using namespace std;

#define NULL -1

template <typename T>
struct node {
	T data;
	node<T>* parent;
	node<T>* left;
	node<T>* right;
	node(T data, node<T>* parent) : data(data), parent(parent), left(nullptr), right(nullptr) {
	}
};

template <typename T>
class binary_tree {
public:
	binary_tree() : root(nullptr) {
	}
	binary_tree(T data) : root(new node<T>(data, nullptr)) {
		nodes.push_back(root);
	}
	~binary_tree() {
		delete root;
	}
	int size() {
		return nodes.size();
	}
	bool empty() {
		return (size() == 0);
	}
	node<T>* getRoot() {
		return root;
	}
	bool isRoot(node<T>* node) {
		if (root == nullptr)
			return false;
		return (node == root);
	}
	bool isExternal(node<T>* node) {
		if (root == nullptr)
			return false;
		return (node->left == nullptr && node->right == nullptr);
	}
	void insert(T parentData, T data) {
		if (root == nullptr) {
			root = new node<T>(data, nullptr);
			nodes.push_back(root);
			return;
		}
		if (find(data, nodes) != -1) {
			// AlreadyExist
			return;
		}
		int parentIndex = find(parentData, nodes);
		if (parentIndex == -1) {
			// ParentNotFound
			return;
		}
		node<T>* parentNode = nodes[parentIndex];
		if (parentNode->left != nullptr && parentNode->right != nullptr) {
			// ChildFull
			return;
		}
		node<T>* newNode = new node<T>(data, parentNode);
		if (parentNode->left == nullptr)
			parentNode->left = newNode;
		else if (parentNode->right == nullptr)
			parentNode->right = newNode;
		nodes.push_back(newNode);
	}
	void erase(T data) {
		int index = find(data, nodes);
		if (index == -1) {
			// NotFound
			return;
		}
		deleteNode(nodes[index]);
	}
private:
	node<T>* root;
	vector<node<T>*> nodes;
	int find(T data, vector<node<T>*>& list) {
		for (int i = 0; i < list.size(); i++) {
			if (list[i]->data == data) {
				return i;
			}
		}
		return -1;
	}
	void deleteNode(node<T>* curNode) {
		if (curNode == nullptr) return;
		deleteNode(curNode->left);
		deleteNode(curNode->right);

		if (curNode == root) {
			root = nullptr;
		}
		else {
			node<T>* parentNode = curNode->parent;
			if (curNode == parentNode->left)
				parentNode->left = nullptr;
			else
				parentNode->right = nullptr;
		}
		nodes.erase(nodes.begin() + find(curNode->data, nodes));
		delete curNode;
	}
};

template <typename T>
void preOrder(binary_tree<T>& tree, node<T>* node) {
	if (node == nullptr) return;
	cout << node->data << " ";
	preOrder(tree, node->left);
	preOrder(tree, node->right);
}

template <typename T>
void postOrder(binary_tree<T>& tree, node<T>* node) {
	if (node == nullptr) return;
	postOrder(tree, node->left);
	postOrder(tree, node->right);
	cout << node->data << " ";
}

template <typename T>
void inOrder(binary_tree<T>& tree, node<T>* node) {
	if (node == nullptr) return;
	inOrder(tree, node->left);
	cout << node->data << " ";
	inOrder(tree, node->right);
}
