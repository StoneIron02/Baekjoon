#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string str;
    cin >> str;

    transform(str.begin(), str.end(), str.begin(), ::toupper);
    cout << str;
}