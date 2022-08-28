#include <iostream>
#include <vector>
using namespace std;

#define NULL -1

template <typename T>
struct node {
	T data;
	node<T>* parent;
	vector<node<T>*> childs;
	node(T data, node<T>* parent) : data(data), parent(parent) {
	}
};

template <typename T>
class tree {
public:
	tree() : root(nullptr) {
	}
	tree(T data) : root(new node<T>(data, nullptr)) {
		nodes.push_back(root);
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
		return (node->childs.size() == 0);
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
		node<T>* newNode = new node<T>(data, parentNode);
		parentNode->childs.push_back(newNode);
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
		for (int i = 0; i < curNode->childs.size(); i++)
			deleteNode(curNode->childs[i]);

		if (curNode == root) {
			root = nullptr;
		}
		else {
			node<T>* parentNode = curNode->parent;
			parentNode->childs.erase(parentNode->childs.begin() + find(curNode->data, parentNode->childs));
			nodes.erase(nodes.begin() + find(curNode->data, nodes));
		}
		delete curNode;
	}
};

template <typename T>
void preOrder(tree<T>& tree, node<T>* node) {
	if (node == nullptr) return;
	cout << node->data << " ";
	for (int i = 0; i < node->childs.size(); i++) {
		preOrder(tree, node->childs[i]);
	}
}

template <typename T>
void postOrder(tree<T>& tree, node<T>* node) {
	if (node == nullptr) return;
	for (int i = 0; i < node->childs.size(); i++) {
		postOrder(tree, node->childs[i]);
	}
	cout << node->data << " ";
}
