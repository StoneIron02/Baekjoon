#include <iostream>
#include <vector>
using namespace std;

struct p {
	int key;
	int parentKey;
	p(int parentKey, int key) : parentKey(parentKey), key(key) {
	}
	bool operator<(p& otherNode) {
		return (parentKey < otherNode.parentKey);
	}
	friend ostream& operator<<(ostream& out, p node) {
		out << node.key;
		return out;
	}
};

#define NULL p(0, 0)

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

int cnt = 0;

template <typename T>
void preOrder(tree<T>& tree, node<T>* node) {
	if (node == nullptr) return;
	if (tree.isExternal(node))
		cnt++;
	for (int i = 0; i < node->childs.size(); i++) {
		preOrder(tree, node->childs[i]);
	}
}

template <typename T>
class priority_queue {
public:
	priority_queue() {
		isMinHeap = true;
		arr.push_back(NULL);
	}
	priority_queue(int capacity) {
		isMinHeap = true;
		arr.resize(capacity);
		arr.push_back(NULL);
	}
	priority_queue(int capacity, bool isMinHeap) : isMinHeap(isMinHeap) {
		arr.resize(capacity);
		arr.push_back(NULL);
	}
	int size() {
		return (arr.size() - 1);
	}
	bool empty() {
		return (size() == 0);
	}
	void push(T data) {
		arr.push_back(data);
		upHeap(size());
	}
	T pop() {
		T result = arr[1];
		arr[1] = arr[size()];
		arr.pop_back();
		downHeap(1);
		return result;
	}
	T top() {
		if (size() == 0) {
			// QueueEmpty
			return NULL;
		}
		return arr[1];
	}
private:
	bool isMinHeap;
	vector<T> arr;
	void swap(int index1, int index2) {
		arr[0] = arr[index1];
		arr[index1] = arr[index2];
		arr[index2] = arr[0];
	}
	void upHeap(int curIndex) {
		if (curIndex == 1) return;
		int parentIndex = curIndex / 2;
		if (isMinHeap) {
			if (arr[curIndex] < arr[parentIndex]) {
				swap(curIndex, parentIndex);
				upHeap(parentIndex);
			}
		}
		else {
			if (arr[parentIndex] < arr[curIndex]) {
				swap(curIndex, parentIndex);
				upHeap(parentIndex);
			}
		}
	}
	void downHeap(int curIndex) {
		int leftIndex = curIndex * 2;
		int rightIndex = curIndex * 2 + 1;
		int childIndex;
		if (size() < leftIndex) {
			return;
		}
		else if (size() == leftIndex) {
			childIndex = leftIndex;
		}
		else {
			if (isMinHeap) {
				if (arr[leftIndex] < arr[rightIndex])
					childIndex = leftIndex;
				else
					childIndex = rightIndex;
			}
			else {
				if (arr[rightIndex] < arr[leftIndex])
					childIndex = leftIndex;
				else
					childIndex = rightIndex;
			}
		}
		if (isMinHeap) {
			if (arr[childIndex] < arr[curIndex]) {
				swap(curIndex, childIndex);
				downHeap(childIndex);
			}
		}
		else {
			if (arr[curIndex] < arr[childIndex]) {
				swap(curIndex, childIndex);
				downHeap(childIndex);
			}
		}
	}
};

int main() {
	int n;
	cin >> n;
	tree<int> t;
	priority_queue<p> list;
	for (int i = 0; i < n; i++) {
		int parent;
		cin >> parent;
		list.push(p(parent, i));
	}
	for (int i = 0; i < n; i++) {
		p data = list.pop();
		t.insert(data.parentKey, data.key);
	}
	int del;
	cin >> del;
	t.erase(del);
	preOrder(t, t.getRoot());
	cout << cnt;
}