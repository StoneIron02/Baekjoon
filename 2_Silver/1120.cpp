#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string a, b;
    cin >> a >> b;
    int minMismatch = 50;
    for (int i = 0; i < b.size() - a.size() + 1; i++) {
        int miss = 0;
        for (int j = 0; j < a.size(); j++) {
            if (a[j] != b[i + j])
                miss++;
        }
        minMismatch = miss < minMismatch ? miss : minMismatch;
    }

    cout << minMismatch;
}