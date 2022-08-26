#include <iostream>
#include <string>
using namespace std;

#define LEFT 1
#define RIGHT 0

#define NULL ""

template <typename T>
class Deque {
public:
	Deque(int capacity) : capacity(capacity) {
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
	void push_front(T data) {
		if (size() == capacity) {
			// QueueFull
			return;
		}
		f = (f - 1 + capacity) % capacity;
		arr[f] = data;
		n++;
	}
	void push_back(T data) {
		if (size() == capacity) {
			// QueueFull
			return;
		}
		arr[r] = data;
		r = (r + 1) % capacity;
		n++;
	}
	T pop_front() {
		if (size() == 0) {
			// QueueEmpty
			return NULL;
		}
		T data = arr[f];
		f = (f + 1) % capacity;
		n--;
		return data;
	}
	T pop_back() {
		if (size() == 0) {
			// QueueEmpty
			return NULL;
		}
		T data = arr[(r - 1 + capacity) % capacity];
		r = (r - 1 + capacity) % capacity;
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
		return arr[(r - 1 + capacity) % capacity];
	}
private:
	int n;
	int f, r;
	int capacity;
	T* arr;
};

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		string p;
		cin >> p;
		int n;
		cin >> n;
		bool direction = LEFT;
		bool correct = true;
		Deque<string> deque = Deque<string>(n);
		string temp;
		getline(cin, temp, '[');
		for (int j = 0; j < n - 1; j++) {
			string num;
			getline(cin, num, ',');
			deque.push_back(num);
		}
		string num;
		getline(cin, num, ']');
		if (num != "") deque.push_back(num);

		for (int j = 0; j < p.size(); j++) {
			if (p[j] == 'R') {
				direction = !direction;
			}
			else if (p[j] == 'D') {
				string value;
				if (direction)
					value = deque.pop_front();
				else
					value = deque.pop_back();
				
				if (value == NULL)
					correct = false;
			}
		}

		if (!correct) {
			cout << "error\n";
			continue;
		}
		cout << "[";
		while (deque.size() > 1) {
			if (direction)
				cout << deque.pop_front() << ",";
			else
				cout << deque.pop_back() << ",";
		}
		if (direction)
			cout << deque.pop_front() << "]\n";
		else
			cout << deque.pop_back() << "]\n";
	}
}