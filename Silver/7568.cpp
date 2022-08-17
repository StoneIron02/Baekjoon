#include <iostream>
#include <vector>
using namespace std;

struct body {
	int weight;
	int height;
	body(int weight, int height) : weight(weight), height(height) {
	}
	bool isLargerThan(body* x) {
		return (weight > x->weight && height > x->height);
	}
};

int main() {
	int n;
	cin >> n;
	vector<body*> bodies;
	for (int i = 0; i < n; i++) {
		int w, h;
		cin >> w >> h;
		bodies.push_back(new body(w, h));
	}
	for (int i = 0; i < n; i++) {
		int count = 0;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (bodies[j]->isLargerThan(bodies[i]))
				count++;
		}
		cout << count + 1 << " ";
	}
}