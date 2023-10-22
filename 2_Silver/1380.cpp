#include <iostream>
#include <map>

using namespace std;

string name[101];
bool cnt[101];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t = 1;
    while (true) {
        int n;
        cin >> n;
        if (n == 0)
            break;
        cin.ignore();
        for (int i = 1; i <= n; i++) {
            getline(cin, name[i]);
        }

        for (int i = 1; i <= n; i++) {
            cnt[i] = true;
        }
        for (int i = 1; i <= 2 * n - 1; i++) {
            int num;
            char p;
            cin >> num >> p;
            cnt[num] = !cnt[num];
        }
        for (int i = 1; i <= n; i++) {
            if (!cnt[i]) {
                cout << t << " " << name[i] << "\n";
                break;
            }
        }
        t++;
    }
}