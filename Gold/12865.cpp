#include <iostream>
using namespace std;

struct item {
	int weight;
	int value;
	item() : weight(-1), value(-1) {
	}
	item(int weight, int value) : weight(weight), value(value) {
	}
};

struct knapsack {
	int totalValue;
	int path; // left = 01, up = 10
	knapsack() : totalValue(0), path(0) {
	}
	knapsack(int length, int path) : totalValue(length), path(path) {
	}
};

knapsack** KNAPSACK_0_1(item* items, int n, int maxWeight) {
	knapsack** table = new knapsack * [n + 1];
	for (int i = 0; i < n + 1; i++) {
		table[i] = new knapsack[maxWeight + 1];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= maxWeight; j++) {
			table[i][j].totalValue = table[i - 1][j].totalValue;
			table[i][j].path = 0b10;
			int curWeight = items[i - 1].weight;
			int curValue = items[i - 1].value;
			if (curWeight <= j) {
				if (table[i - 1][j - curWeight].totalValue + curValue > table[i][j].totalValue) {
					table[i][j].totalValue = table[i - 1][j - curWeight].totalValue + curValue;
					table[i][j].path = 0b01;
				}
			}
		}
	}
	return table;
}

int KNAPSACK_0_1_value(knapsack** table, int n, int maxWeight) {
	return table[n][maxWeight].totalValue;
}

int main() {
	int n, k;
	cin >> n >> k;
	item* items = new item[n];
	for (int i = 0; i < n; i++) {
		int w, v;
		cin >> w >> v;
		items[i] = item(w, v);
	}
	knapsack** table = KNAPSACK_0_1(items, n, k);
	cout << KNAPSACK_0_1_value(table, n, k) << "\n";
}