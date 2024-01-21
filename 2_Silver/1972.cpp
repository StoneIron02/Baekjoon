#include <iostream>
#include <set>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string str;
    while (true) {
        cin >> str;
        if (str == "*") break;

        bool flag = true;
        for (int l = 1; l <= str.size() - 1; l++) {
            set<string> subs;
            for (int i = 0; i < str.size() - l; i++) {
                int j = i + l;
                string sub;
                sub += str[i];
                sub += str[j];
                if (subs.find(sub) != subs.end()) {
                    flag = false;
                    break;
                }
                subs.insert(sub);
            }
            if (!flag) break;
        }
        if (flag) {
            cout << str << " is surprising.\n";
        } else {
            cout << str << " is NOT surprising.\n";
        }
    }

}