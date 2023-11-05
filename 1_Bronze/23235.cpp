#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t = 1;
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        int tmp;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
        }
        cout << "Case " << t << ": Sorting... done!\n";
        t++;
    }
}