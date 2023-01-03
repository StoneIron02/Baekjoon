#include <iostream>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n;
	cin >> n;

	int case1 = n * 0.78;
	int case2 = n * 0.8 + n * 0.2 * 0.78;

	cout << case1 << " " << case2;
}