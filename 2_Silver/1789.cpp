#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

    long long num;
    cin >> num;
    long long sum = 0;
    long long cur = 0;
    while (sum <= num - cur) {
        sum += cur;
        cur++;
    }
    cur--;

    cout << cur;
}