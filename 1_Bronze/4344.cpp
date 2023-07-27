#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int arr[1000];

int main() {
	int c;
	cin >> c;
    while (c--) {
        int n;
        cin >> n;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
        }
        double avg = (double)sum / n;
        sort(arr, arr + n);
        int idx = upper_bound(arr, arr + n, avg) - arr;
        int cnt = n - idx;
        double ratio = (double)cnt / n * 100;
        cout << fixed << setprecision(3) << ratio << "%\n";
    }
}
