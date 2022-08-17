#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct word {
	string key;
	word(string key) : key(key) {
	}
	bool isSame(word* p) {
		return (key == p->key);
	}
	bool isSmallerThan(word* p) {
		if (key.size() == p->key.size()) {
			for (int i = 0; i < key.size(); i++) {
				if (key[i] == p->key[i]) continue;
				else return (key[i] < p->key[i]);
			}
		}
		else {
			return (key.size() < p->key.size());
		}
	}
	friend ostream& operator<<(ostream& out, word* p) {
		out << p->key;
		return out;
	}
};

template <typename T>
class PQ {
public:
	PQ<T>() {
		arr.push_back(NULL);
	}
	int size() {
		return (arr.size() - 1);
	}
	void insert(T data) {
		arr.push_back(data);
		upHeap(size());
	}
	T removeMin() {
		T result = arr[1];
		arr[1] = arr[size()];
		arr.pop_back();
		downHeap(1);
		return result;
	}
	bool contains(T data) {
		for (int i = 1; i < arr.size(); i++) {
			if (arr[i]->isSame(data))
				return true;
		}
		return false;
	}
private:
	vector<T> arr;
	void upHeap(int curIndex) {
		if (curIndex == 1) return;
		int parentIndex = curIndex / 2;
		if (arr[curIndex]->isSmallerThan(arr[parentIndex])) {
			arr[0] = arr[curIndex];
			arr[curIndex] = arr[parentIndex];
			arr[parentIndex] = arr[0];
			upHeap(parentIndex);
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
			if (arr[leftIndex]->isSmallerThan(arr[rightIndex]))
				childIndex = leftIndex;
			else
				childIndex = rightIndex;
		}

		if (arr[childIndex]->isSmallerThan(arr[curIndex])) {
			arr[0] = arr[curIndex];
			arr[curIndex] = arr[childIndex];
			arr[childIndex] = arr[0];
			downHeap(childIndex);
		}
	}
};

int main() {
	int n;
	cin >> n;
	PQ<word*> pq = PQ<word*>();
	for (int i = 0; i < n; i++) {
		string key;
		cin >> key;
		word* data = new word(key);
		if (pq.contains(data)) continue;
		pq.insert(data);
	}

	int size = pq.size();
	for (int i = 0; i < size; i++) {
		cout << pq.removeMin() << "\n";
	}
}