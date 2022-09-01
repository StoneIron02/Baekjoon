#include <iostream>
using namespace std;

#define NULL -1

template <typename T>
struct node {
	T key;
	node<T>* parent;
	node<T>* left;
	node<T>* right;
	node(T key) : key(key), parent(nullptr), left(nullptr), right(nullptr) {
	}
};

template <typename T>
class binary_search_tree {
public:
	binary_search_tree() : root(nullptr), n(0) {
	}
	binary_search_tree(T key) : root(new node<T>(key)), n(1) {
	}
	~binary_search_tree() {
		delete root;
	}
	int size() {
		return n;
	}
	bool empty() {
		return (size() == 0);
	}
	node<T>* getRoot() {
		return root;
	}
	node<T>* search(node<T>* curNode, T key) {
		while (curNode != nullptr && key != curNode->key) {
			if (key < curNode->key)
				curNode = curNode->left;
			else
				curNode = curNode->right;
		}
		return curNode;
	}
	node<T>* minimum(node<T>* curNode) {
		while (curNode->left != nullptr) {
			curNode = curNode->left;
		}
		return curNode;
	}
	node<T>* maximum(node<T>* curNode) {
		while (curNode->right != nullptr) {
			curNode = curNode->right;
		}
		return curNode;
	}
	node<T>* successor(node<T>* curNode) {
		if (curNode->right != nullptr)
			return minimum(curNode->right);

		node<T>* parentNode = curNode->parent;
		while (parentNode!= nullptr && curNode == parentNode->right) {
			curNode = parentNode;
			parentNode = parentNode->parent;
		}
		return parentNode;
	}
	node<T>* predecessor(node<T>* curNode) {
		if (curNode->left != nullptr)
			return maximum(curNode->left);

		node<T>* parentNode = curNode->parent;
		while (parentNode != nullptr && curNode == parentNode->left) {
			curNode = parentNode;
			parentNode = parentNode->parent;
		}
		return parentNode;
	}
	void insert(T key) {
		node<T>* newNode = new node<T>(key); // curNode
		node<T>* parentNode = nullptr; // parentNode
		node<T>* curNode = root;
		while (curNode != nullptr) {
			parentNode = curNode;
			if (newNode->key < curNode->key)
				curNode = curNode->left;
			else
				curNode = curNode->right;
		}

		newNode->parent = parentNode;
		if (parentNode == nullptr)
			root = newNode;
		else if (newNode->key < parentNode->key)
			parentNode->left = newNode;
		else
			parentNode->right = newNode;
		n++;
	}
	void erase(T key) {
		node<T>* deleteNode = search(root, key);
		if (deleteNode == nullptr) {
			// NotFound
			return;
		}
		
		if (deleteNode->left == nullptr)
			transplant(deleteNode, deleteNode->right);
		else if (deleteNode->right == nullptr)
			transplant(deleteNode, deleteNode->left);
		else {
			node<T>* successor = minimum(deleteNode->right);
			if (successor->parent != deleteNode) {
				transplant(successor, successor->right);
				successor->right = deleteNode->right;
				successor->right->parent = successor;
			}
			transplant(deleteNode, successor);
			successor->left = deleteNode->left;
			successor->left->parent = successor;
		}
		delete deleteNode;
		n--;
	}
private:
	node<T>* root;
	int n;
	void transplant(node<T>* u, node<T>* v) {
		if (u->parent == nullptr)
			root = v;
		else if (u == u->parent->left)
			u->parent->left = v;
		else
			u->parent->right = v;
		if (v != nullptr)
			v->parent = u->parent;
	}
};

template <typename T>
void inOrder(binary_search_tree<T>& tree, node<T>* node) {
	if (node == nullptr) return;
	inOrder(tree, node->left);
	cout << node->data << " ";
	inOrder(tree, node->right);
}
