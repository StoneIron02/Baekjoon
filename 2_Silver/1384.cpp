#include <iostream>

using namespace std;

string name[20];
int isNasty[20][20];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int cnt = 1;
    while (true) {
        int n;
        cin >> n;
        if (n == 0)
            return 0;

        cout << "Group " << cnt << "\n";
        for (int i = 0; i < n; i++) {
            cin >> name[i];
            for (int j = 0; j < n - 1; j++) {
                char c;
                cin >> c;
                if (c == 'N')
                    isNasty[i][j] = true;
                else
                    isNasty[i][j] = false;
            }
        }

        bool flag = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (isNasty[i][j]) {
                    flag = false;
                    cout << name[(i - (j + 1) + n) % n] << " was nasty about " << name[i] << "\n";
                }
            }
        }
        if (flag) {
            cout << "Nobody was nasty\n";
        }

        cout << "\n";
        cnt++;
    }
}