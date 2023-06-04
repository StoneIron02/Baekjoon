#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    while (true) {
        int num;
        cin >> num;
        if (num == 0)
            break;

        int count = num * (num + 1) / 2;
        cout << count << "\n";
    }
}