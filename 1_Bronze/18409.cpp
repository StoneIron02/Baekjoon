#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    string str;
    cin >> str;
    int cnt = 0;
    for (char c : str) {
        switch (c) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                cnt++;
                break;
        }
    }

    cout << cnt;
}