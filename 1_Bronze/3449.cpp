#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        int dist = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i])
                dist++;
        }
        cout << "Hamming distance is " << dist << ".\n";
    }
}