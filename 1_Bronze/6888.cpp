#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int x, y;
    cin >> x >> y;
    for (int i = x; i <= y; i += 60) {
        cout << "All positions change in year " << i << "\n";
    }
}