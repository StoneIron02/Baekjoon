#include <iostream>
using namespace std;

#define NULL -1

template <typename T>
struct node {
	T data;
	node<T>* next;
	node(T data) : data(data) {
		next = nullptr;
	}
	node(T data, node<T>* next) : data(data), next(next) {
	}
};

template <typename T>
class singly_linked_list {
public:
	singly_linked_list() : head(nullptr), tail(nullptr), n(0) {
	}
	~singly_linked_list() {
		delete head;
		delete tail;
	}
	int size() {
		return n;
	}
	bool empty() {
		return (size() == 0);
	}
	void push_front(T data) {
		node<T>* newNode = new node<T>(data, head);
		head = newNode;
		if (empty()) {
			tail = newNode;
		}
		n++;
	}
	void push_back(T data) {
		node<T>* newNode = new node<T>(data);
		if (empty()) {
			head = tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
		n++;
	}
	void insert(int index, T data) {
		if (index < 0 || index > size()) {
			// OutOfIndex
			return;
		}
		else if (index == 0) {
			push_front(data);
		}
		else if (index == size()) {
			push_back(data);
		}
		else {
			node<T>* newNode = new node<T>(data);
			node<T>* curNode = head;
			for (int i = 1; i < index; i++) {
				curNode = curNode->next;
			}
			newNode->next = curNode->next;
			curNode->next = newNode;
			n++;
		}
	}
	void pop_front() {
		node<T>* deleteNode = head;
		if (size() == 1)
			head = tail = nullptr;
		else
			head = head->next;
		delete deleteNode;
		n--;
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
		else if (index == 0) {
			pop_front();
			return;
		}
		node<T>* prevNode = nullptr;
		node<T>* curNode = head;
		for (int i = 0; i < index; i++) {
			prevNode = curNode;
			curNode = curNode->next;
		}
		prevNode->next = curNode->next;
		if (curNode == tail) {
			tail = prevNode;
		}
		delete curNode;
		n--;
	}
	T front() {
		if (empty()) {
			// ListEmpty
			return NULL;
		}
		return head->data;
	}
	T back() {
		if (empty()) {
			// ListEmpty
			return NULL;
		}
		return tail->data;
	}
private:
	node<T>* head;
	node<T>* tail;
	int n;
};
