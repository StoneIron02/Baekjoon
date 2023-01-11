#include <iostream>
#include <vector>
using namespace std;

#define NULL -1

template <typename T>
class priority_queue {
public:
	priority_queue() : isMinPQ(true) {
	}
	priority_queue(bool isMinPQ) : isMinPQ(isMinPQ) {
	}
	int size() {
		return arr.size();
	}
	bool empty() {
		return (size() == 0);
	}
	void push(T data) {
		int i;
		for (i = 0; i < arr.size(); i++) {
			if (isMinPQ) {
				if (arr[i] < data)
					break;
			}
			else {
				if (data < arr[i])
					break;
			}
		}
		arr.insert(arr.begin() + i, data);
	}
	T pop() {
		if (empty()) {
			// QueueEmpty
			return NULL;
		}
		T result = arr.back();
		arr.pop_back();
		return result;
	}
	T top() {
		if (empty()) {
			// QueueEmpty
			return NULL;
		}
		return arr.back();
	}
private:
	bool isMinPQ;
	vector<T> arr;
	int getTopIndex() {
		int topIndex = 0;
		for (int curIndex = 1; curIndex < arr.size(); curIndex++) {
			if (isMinPQ) {
				if (arr[curIndex] < arr[topIndex])
					topIndex = curIndex;
			}
			else {
				if (arr[topIndex] < arr[curIndex])
					topIndex = curIndex;
			}
		}
		return topIndex;
	}
};

/*
struct node {
	int key;
	node(int key) : key(key) {
	}
	bool operator<(node& otherNode) {
		return (key < otherNode.key);
	}
	friend ostream& operator<<(ostream& out, node node) {
		out << node.key;
		return out;
	}
};
*/
