#include <iostream>
#include <set>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    set<int> list;
    for (int i = 0; i < 5; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < str.size() - 2; j++) {
            if (str[j] == 'F' && str[j + 1] == 'B' && str[j + 2] == 'I') {
                list.insert(i + 1);
                continue;
            }
        }
    }

    if (list.empty()) {
        cout << "HE GOT AWAY!\n";
    } else {
        for (auto i : list) {
            cout << i << " ";
        }
    }
}