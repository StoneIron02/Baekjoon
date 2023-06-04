#include <iostream>

#define M 0
#define O 1
#define B 2
#define I 3
#define S 4

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    bool arr[5];
    for (int i = 0; i < 5; i++)
        arr[i] = false;

    string str;
    cin >> str;
    for (char c : str) {
        if (c == 'M') {
            arr[M] = true;
        }
        if (c == 'O') {
            arr[O] = true;
        }
        if (c == 'B') {
            arr[B] = true;
        }
        if (c == 'I') {
            arr[I] = true;
        }
        if (c == 'S') {
            arr[S] = true;
        }
    }

    for (int i = 0; i < 5; i++) {
        if (!arr[i]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}