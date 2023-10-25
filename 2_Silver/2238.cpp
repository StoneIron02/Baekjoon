#include <iostream>
#include <queue>

using namespace std;

queue<string> arr[10001];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int u, n;
    cin >> u >> n;
    for (int i = 0; i < n; i++) {
        string name;
        int price;
        cin >> name >> price;
        arr[price].push(name);
    }

    int minSize = 10000;
    int minPrice = -1;
    for (int i = 1; i <= 10000; i++) {
        if (!arr[i].empty() && minSize > arr[i].size()) {
            minSize = arr[i].size();
            minPrice = i;
        }
    }
    cout << arr[minPrice].front() << " " << minPrice;
}