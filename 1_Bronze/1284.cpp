#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    map<int, int> cm;
    cm[0] = 4;
    cm[1] = 2;
    cm[2] = 3;
    cm[3] = 3;
    cm[4] = 3;
    cm[5] = 3;
    cm[6] = 3;
    cm[7] = 3;
    cm[8] = 3;
    cm[9] = 3;

    while (true) {
        string num;
        cin >> num;
        if (num == "0")
            exit(0);

        int cnt = 1;
        for (char c : num) {
            int inum = c - '0';
            cnt += cm[inum] + 1;
        }

        cout << cnt << "\n";
    }
}