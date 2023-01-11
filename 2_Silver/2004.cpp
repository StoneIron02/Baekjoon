#include <iostream>
using namespace std;

long get_2_count(int n) {
	long count2 = 0;
	for (long i = 2; i <= n; i *= 2)
		count2 += n / i;
	return count2;
}

long get_5_count(int n) {
	long count5 = 0;
	for (long i = 5; i <= n; i *= 5)
		count5 += n / i;
	return count5;
}

int main() {
	int n, k;
	cin >> n >> k;

	long totalCount2 = get_2_count(n) - get_2_count(k) - get_2_count(n - k);
	long totalCount5 = get_5_count(n) - get_5_count(k) - get_5_count(n - k);
	cout << (totalCount2 > totalCount5 ? totalCount5 : totalCount2);
}