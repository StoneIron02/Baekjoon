#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cout << i << " ";
        if (i % 6 == 0)
            cout << "Go! ";
    }
    cout << n << " Go!";
}