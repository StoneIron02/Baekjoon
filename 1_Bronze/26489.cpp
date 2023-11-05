#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string str;
    int cnt = 0;
    while (getline(cin, str)) {
        cnt++;
    }
    cout << cnt;
}