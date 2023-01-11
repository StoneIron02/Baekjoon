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
class doubly_linked_list {
public:
	doubly_linked_list() : n(0), header(new node<T>(NULL)), trailer(new node<T>(NULL)) {
		header->next = trailer;
		trailer->prev = header;
	}
	~doubly_linked_list() {
		delete header;
		delete trailer;
	}
	int size() {
		return n;
	}
	bool empty() {
		return (size() == 0);
	}
	void push_front(T data) {
		insert(0, data);
	}
	void push_back(T data) {
		insert(size(), data);
	}
	void insert(int index, T data) {
		if (index < 0 || index > size()) {
			// OutOfIndex
			return;
		}
		node<T>* newNode = new node<T>(data);
		node<T>* curNode = header->next;
		for (int i = 0; i < index; i++) {
			curNode = curNode->next;
		}
		newNode->next = curNode;
		newNode->prev = curNode->prev;
		curNode->prev->next = newNode;
		curNode->prev = newNode;
		n++;
	}
	void pop_front() {
		erase(0);
	}
	void pop_back() {
		erase(size() - 1);
	}
	void erase(int index) {
		if (empty()) {
			// ListEmpty
			return;
		}
		if (index < 0 || index >= size()) {
			// OutOfIndex
			return;
		}
		node<T>* deleteNode = header->next;
		for (int i = 0; i < index; i++) {
			deleteNode = deleteNode->next;
		}
		deleteNode->next->prev = deleteNode->prev;
		deleteNode->prev->next = deleteNode->next;
		delete deleteNode;
		n--;
	}
	T front() {
		if (empty()) {
			// ListEmpty
			return NULL;
		}
		return header->next->data;
	}
	T back() {
		if (empty()) {
			// ListEmpty
			return NULL;
		}
		return trailer->prev->data;
	}
private:
	node<T>* header;
	node<T>* trailer;
	int n;
};
