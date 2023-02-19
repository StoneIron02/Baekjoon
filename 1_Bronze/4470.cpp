#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    cin.get();
    for (int i=1; i<=n; i++) {
        string str;
        getline(cin, str);
        cout << i << ". " << str << "\n";
    }
}