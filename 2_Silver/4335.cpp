#include <iostream>

using namespace std;

bool arr[11];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int left = 1, right = 10;
    bool lie = false;
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        cin.ignore();
        string str;
        getline(cin, str);
        if (str == "too high") {
            if (left > right)
                lie = true;
            for (int i = n; i <= 10; i++)
                arr[i] = true;
            right = n - 1;
        } else if (str == "too low") {
            if (left > right)
                lie = true;
            for (int i = 1; i <= n; i++)
                arr[i] = true;
            left = n + 1;
        } else {
            if (arr[n])
                lie = true;
            if (left > n || n > right)
                lie = true;
            if (left <= n && n <= right && left > right)
                lie = true;

            if (lie) {
                cout << "Stan is dishonest\n";
            } else {
                cout << "Stan is may be honest\n";
            }
            for (int i = 1; i <= 10; i++) {
                arr[i] = false;
            }
            left = 1, right = 10;
            lie = false;
        }
    }
}