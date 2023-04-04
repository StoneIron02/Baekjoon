#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string str[5];
    for (auto & i : str) {
        cin >> i;
    }

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 5; j++) {
            if (str[j].size() > i)
                cout << str[j][i];
        }
    }
}