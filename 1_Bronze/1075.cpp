#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    string n;
    int f;
    cin >> n >> f;
    n = n.substr(0, n.size() - 2);
    for (int i = 0; i < 100; i++) {
        string s = to_string(i);
        if (i < 10)
            s = '0' + s;
        int num = stoi(n + s);
        if (num % f == 0) {
            cout << s;
            exit(0);
        }
    }
}