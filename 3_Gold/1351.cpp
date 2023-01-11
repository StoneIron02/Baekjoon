#include <iostream>
#include <set>
#include <map>
#include <vector>
using namespace std;

map<unsigned long long, unsigned long long> aMap;

unsigned long long dynammic_programming(unsigned long long i, unsigned int p, unsigned int q) {
	if (i == 0)
		return 1;

	if (aMap[i] == 0)
		aMap[i] = dynammic_programming(i / p, p, q) + dynammic_programming(i / q, p, q);
	return aMap[i];
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	unsigned long long n;
	unsigned int p, q;
	cin >> n >> p >> q;
	cout << dynammic_programming(n, p, q);
}