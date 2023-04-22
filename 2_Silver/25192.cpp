#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int result = 0;
    map<string, bool> user;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        if (str == "ENTER") {
            user.clear();
        } else {
            if (!user[str]) {
                result++;
                user[str] = true;
            }
        }
    }

    cout << result;
}