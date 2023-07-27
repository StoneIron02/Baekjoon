#include <iostream>

using namespace std;
bool isMulti[50];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    string origin;
    cin >> origin;
    for (int i = 1; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < origin.size(); j++) {
            if (origin[j] != str[j])
                isMulti[j] = true;
        }
    }
    for (int j = 0; j < origin.size(); j++) {
        if (isMulti[j])
            cout << "?";
        else
            cout << origin[j];
    }
}