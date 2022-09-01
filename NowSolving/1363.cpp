#include <iostream>
using namespace std;

#define NULL -1

#define BLACK true;
#define RED false;
template <typename T>
struct node {
	T key;
	bool color;
	node<T>* parent;
	node<T>* left;
	node<T>* right;
	node() : key(NULL), parent(nullptr), left(nullptr), right(nullptr) {
		color = BLACK;
	}
	node(T key) : key(key), parent(nullptr), left(nullptr), right(nullptr) {
		color = RED;
	}
	node(T key, node<T>* nil) : key(key), parent(nil), left(nil), right(nil) {
		color = RED;
	}
};

long long cnt = 0;

template <typename T>
class red_black_tree {
public:
	red_black_tree() : nil(new node<T>()), root(nil), n(0) {
	}
	red_black_tree(T key) : nil(new node<T>()), root(new node<T>(key, nil)), n(1) {
		root->color = BLACK;
	}
	~red_black_tree() {
		delete nil;
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
		while (curNode != nil) {
			cnt++;
			if (key == curNode->key)
				break;
			if (key < curNode->key)
				curNode = curNode->left;
			else
				curNode = curNode->right;
		}
		return curNode;
	}
	node<T>* minimum(node<T>* curNode) {
		while (curNode->left != nil) {
			curNode = curNode->left;
		}
		return curNode;
	}
	node<T>* maximum(node<T>* curNode) {
		while (curNode->right != nil) {
			curNode = curNode->right;
		}
		return curNode;
	}
	node<T>* successor(node<T>* curNode) {
		if (curNode->right != nil)
			return minimum(curNode->right);

		node<T>* parentNode = curNode->parent;
		while (parentNode != nil && curNode == parentNode->right) {
			curNode = parentNode;
			parentNode = parentNode->parent;
		}
		return parentNode;
	}
	node<T>* predecessor(node<T>* curNode) {
		if (curNode->left != nil)
			return maximum(curNode->left);

		node<T>* parentNode = curNode->parent;
		while (parentNode != nil && curNode == parentNode->left) {
			curNode = parentNode;
			parentNode = parentNode->parent;
		}
		return parentNode;
	}
	void insert(T key) {
		node<T>* newNode = new node<T>(key, nil); // curNode
		node<T>* parentNode = nil; // parentNode
		node<T>* curNode = root;
		while (curNode != nil) {
			parentNode = curNode;
			if (newNode->key < curNode->key)
				curNode = curNode->left;
			else
				curNode = curNode->right;
		}

		newNode->parent = parentNode;
		if (parentNode == nil)
			root = newNode;
		else if (newNode->key < parentNode->key)
			parentNode->left = newNode;
		else
			parentNode->right = newNode;
		n++;
		insertFixup(newNode);
	}
	void erase(T key) {
		node<T>* deleteNode = search(root, key);
		if (deleteNode == nullptr) {
			// NotFound
			return;
		}

		node<T>* successor = deleteNode;
		bool successor_original_color = successor->color;
		node<T>* fixupNode;
		if (deleteNode->left == nil) {
			fixupNode = deleteNode->right;
			transplant(deleteNode, deleteNode->right);
		}
		else if (deleteNode->right == nil) {
			fixupNode = deleteNode->left;
			transplant(deleteNode, deleteNode->left);
		}
		else {
			successor = minimum(deleteNode->right);
			successor_original_color = successor->color;
			fixupNode = successor->right;
			if (successor->parent == deleteNode)
				fixupNode->parent = successor;
			else {
				transplant(successor, successor->right);
				successor->right = deleteNode->right;
				successor->right->parent = successor;
			}
			transplant(deleteNode, successor);
			successor->left = deleteNode->left;
			successor->left->parent = successor;
			successor->color = deleteNode->color;
		}
		delete deleteNode;
		n--;
		if (successor_original_color)
			deleteFixup(fixupNode);
	}
private:
	node<T>* nil;
	node<T>* root;
	int n;
	void rotateLeft(node<T>* x) {
		node<T>* y = x->right;
		x->right = y->left;
		if (y->left != nil)
			y->left->parent = x;
		y->parent = x->parent;
		if (x->parent == nil)
			root = y;
		else if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
		y->left = x;
		x->parent = y;
	}
	void rotateRight(node<T>* x) {
		node<T>* y = x->left;
		x->left = y->right;
		if (y->right != nil)
			y->right->parent = x;
		y->parent = x->parent;
		if (x->parent == nil)
			root = y;
		else if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
		y->right = x;
		x->parent = y;
	}
	void transplant(node<T>* u, node<T>* v) {
		if (u->parent == nil)
			root = v;
		else if (u == u->parent->left)
			u->parent->left = v;
		else
			u->parent->right = v;
		v->parent = u->parent;
	}
	void insertFixup(node<T>* z) {
		while (!z->parent->color) {
			node<T>* y; // uncle node
			if (z->parent == z->parent->parent->left) { // Parent are the left child of Grandparent
				y = z->parent->parent->right;
				if (!y->color) { // Recoloring
					z->parent->color = BLACK;
					y->color = BLACK;
					z->parent->parent->color = RED;
					z = z->parent->parent;
				}
				else { // Restructuring
					if (z == z->parent->right) {
						z = z->parent;
						rotateLeft(z);
					}
					z->parent->color = BLACK;
					z->parent->parent->color = RED;
					rotateRight(z->parent->parent);
				}
			}
			else { // Parent are the right child of Grandparent
				y = z->parent->parent->left;
				if (!y->color) { // Recoloring
					z->parent->color = BLACK;
					y->color = BLACK;
					z->parent->parent->color = RED;
					z = z->parent->parent;
				}
				else { // Restructuring
					if (z == z->parent->left) {
						z = z->parent;
						rotateRight(z);
					}
					z->parent->color = BLACK;
					z->parent->parent->color = RED;
					rotateLeft(z->parent->parent);
				}
			}
		}
		root->color = BLACK;
	}
	void deleteFixup(node<T>* x) {
		while (x != root && x->color) {
			if (x == x->parent->left) {
				node<T>* w = x->parent->right; // uncle node
				if (!w->color) {
					w->color = BLACK;
					x->parent->color = RED;
					rotateLeft(x->parent);
					w = x->parent->right;
				}
				if (w->left->color && w->right->color) {
					w->color = RED;
					x = x->parent;
				}
				else {
					if (w->right->color) {
						w->left->color = BLACK;
						w->color = RED;
						rotateRight(w);
						w = x->parent->right;
					}
					w->color = x->parent->color;
					x->parent->color = BLACK;
					w->right->color = BLACK;
					rotateLeft(x->parent);
					x = root;
				}
			}
			else {
				node<T>* w = x->parent->left; // uncle node
				if (!w->color) {
					w->color = BLACK;
					x->parent->color = RED;
					rotateRight(x->parent);
					w = x->parent->left;
				}
				if (w->right->color && w->left->color) {
					w->color = RED;
					x = x->parent;
				}
				else {
					if (w->left->color) {
						w->right->color = BLACK;
						w->color = RED;
						rotateLeft(w);
						w = x->parent->left;
					}
					w->color = x->parent->color;
					x->parent->color = BLACK;
					w->left->color = BLACK;
					rotateRight(x->parent);
					x = root;
				}
			}
		}
		x->color = BLACK;
	}
};

template <typename T>
void inOrder(red_black_tree<T>& tree, node<T>* node) {
	if (node == nullptr) return;
	inOrder(tree, node->left);
	cout << node->data << " ";
	inOrder(tree, node->right);
}

int main() {
	int n;
	cin >> n;
	int k;
	cin >> k;
	red_black_tree<int> rbt;
	for (int i = 0; i < k; i++) {
		int num;
		cin >> num;
		rbt.insert(num);
	}
	for (int i = 1; i <= n; i++) {
		rbt.search(rbt.getRoot(), i);
	}
	cout << cnt;
}