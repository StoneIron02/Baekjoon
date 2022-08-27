#include <iostream>
using namespace std;

#define NULL -1

template <typename T>
struct node {
	T data;
	node<T>* prev;
	node<T>* next;
	node(T data) : data(data), prev(nullptr), next(nullptr) {
	}
	node(T data, node<T>* prev, node<T>* next) : data(data), prev(prev), next(next) {
	}
};

template <typename T>
class list { // = Sequence
public:
	list() : n(0) {
		header = trailer = new node<T>(NULL);
		header->next = trailer;
		trailer->prev = header;
	}
	int size() {
		return n;
	}
	bool empty() {
		return (size() == 0);
	}
	node<T>* begin() {
		return header->next;
	}
	node<T>* end() {
		return trailer->prev;
	}
	node<T>* atIndex(int index) {
		if (index < 0 || index > size()) {
			// OutOfIndex
			return nullptr;
		}
		node<T>* curNode = begin();
		for (int i = 0; i < index; i++) {
			curNode = curNode->next;
		}
		return curNode;
	}
	int indexOf(node<T>* pos) {
		node<T>* curNode = begin();
		for (int i = 0; i < n; i++) {
			if (curNode == pos) {
				return i;
			}
		}
		return -1;
	}
	void push_front(T data) {
		insert(begin(), data);
	}
	void push_back(T data) {
		insert(end()->next, data);
	}
	void insert(node<T>* pos, T data) {
		node<T>* newNode = new node<T>(data);
		newNode->next = pos;
		newNode->prev = pos->prev;
		pos->prev->next = newNode;
		pos->prev = newNode;
		n++;
	}
	void pop_front() {
		erase(begin());
	}
	void pop_back() {
		erase(end());
	}
	void erase(node<T>* pos) {
		if (empty()) {
			// ListEmpty
			return;
		}
		pos->next->prev = pos->prev;
		pos->prev->next = pos->next;
		delete pos;
		n--;
	}
	T front() {
		if (empty()) {
			// ListEmpty
			return NULL;
		}
		return begin()->data;
	}
	T back() {
		if (empty()) {
			// ListEmpty
			return NULL;
		}
		return end()->data;
	}
private:
	node<T>* header;
	node<T>* trailer;
	int n;
};
