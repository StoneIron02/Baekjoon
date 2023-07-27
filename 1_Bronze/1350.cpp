#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int arr[50];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int clusterSize;
    cin >> clusterSize;

    long long total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i] / clusterSize;
        if (arr[i] % clusterSize != 0)
            total++;
    }
    cout << (total * clusterSize);
}