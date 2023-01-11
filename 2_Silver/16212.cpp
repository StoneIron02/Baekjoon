#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[500000];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a + n);

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}