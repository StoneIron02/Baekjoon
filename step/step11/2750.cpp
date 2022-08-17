#include <iostream>
#include <vector>
using namespace std;

class PQ {
public:
	void insert(int x) {
		arr.push_back(x);
		for (int i = arr.size() - 2; i >= 0; i--) {
			if (arr[i] <= arr[i + 1])
				break;
			int tmp = arr[i + 1];
			arr[i + 1] = arr[i];
			arr[i] = tmp;
		}
	}
	void print() {
		for (int i = 0; i < arr.size(); i++) {
			cout << arr[i] << endl;
		}
	}
private:
	vector<int> arr;
};

int main() {
	int n;
	cin >> n;
	PQ pq = PQ();
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		pq.insert(num);
	}
	pq.print();
}