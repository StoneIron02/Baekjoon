#include <iostream>
using namespace std;

struct node {
	int data;
	int priority;
	node(int data, int priority) : data(data), priority(priority) {
	}
};

template <typename T>
class Queue {
public:
	Queue(int capacity) : capacity(capacity) {
		arr = new T[capacity];
		f = r = 0;
		n = 0;
	}
	int size() {
		return n;
	}
	bool empty() {
		return (size() == 0);
	}
	void push(T data) {
		if (size() == capacity) {
			// QueueFull
			return;
		}
		arr[r] = data;
		r = (r + 1) % capacity;
		n++;
	}
	T pop() {
		if (size() == 0) {
			// QueueEmpty
			return NULL;
		}
		T data = arr[f];
		f = (f + 1) % capacity;
		n--;
		return data;
	}
	T front() {
		if (size() == 0) {
			// QueueEmpty
			return NULL;
		}
		return arr[f];
	}
	T back() {
		if (size() == 0) {
			// QueueEmpty
			return NULL;
		}
		return arr[r - 1];
	}
private:
	int n;
	int f, r;
	int capacity;
	T* arr;
};

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	int t;
	cin >> t;
	for (int w = 0; w < t; w++) {
		int n, m;
		cin >> n >> m;
		int* priorityCount = new int[10];
		for (int i = 1; i < 10; i++)
			priorityCount[i] = 0;
		Queue<node*> queue = Queue<node*>(n);
		for (int i = 0; i < n; i++) {
			int p;
			cin >> p;
			priorityCount[p]++;
			queue.push(new node(i, p));
		}
		int curPriority = 9;
		while (queue.size() > 0) {
			while (priorityCount[curPriority] == 0)
				curPriority--;
			node* curNode = queue.pop();
			while (curNode->priority != curPriority) {
				queue.push(curNode);
				curNode = queue.pop();
			}
			priorityCount[curPriority]--;
			if (curNode->data == m) {
				cout << (n - queue.size()) << "\n";
				break;
			}
		}
	}
}