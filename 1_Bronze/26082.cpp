#include <iostream>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int a, b, c;
	cin >> a >> b >> c;
	int b_a = b / a;
	int result = b_a * 3 * c;
	cout << result;
}