#include <iostream>
#include <stack>
using namespace std;

#define LINE2 true;
#define LINE3 false;

stack<int> line1;
stack<int> line2;
stack<int> line3;

bool move_line;

void hanoi(int n) {
	if (n == 1) {
		int num = line1.top();
		line1.pop();
		if (move_line) {
			cout << 1 << " " << 2 << endl;
			line2.push(num);
		}
		else {
			cout << 1 << " " << 3 << endl;
			line3.push(num);
		}
		move_line = !move_line;
		return;
	}
	hanoi(n - 1);
	int num = line1.top();
	line1.pop();
	if (move_line) {
		cout << 1 << " " << 2 << endl;
		line2.push(num);
	}
	else {
		cout << 1 << " " << 3 << endl;
		line3.push(num);
	}
	move_line = !move_line;
}

void print() {
	while (!line1.empty()) {
		cout << line1.top() << " ";
		line1.pop();
	}
	cout << endl;
	while (!line2.empty()) {
		cout << line2.top() << " ";
		line2.pop();
	}
	cout << endl;
	while (!line3.empty()) {
		cout << line3.top() << " ";
		line3.pop();
	}
	cout << endl;
}

int main() {
	int n;
	cin >> n;
	for (int i = n; i >= 1; i--)
		line1.push(i);

	if (n % 2 == 0) {
		move_line = LINE2;
	}
	else {
		move_line = LINE3;
	}

	cout << pow(2, n) - 1 << endl;
	hanoi(n);
	print();
}