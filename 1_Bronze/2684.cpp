#include <iostream>

using namespace std;

int cnt[8];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    // 뒤뒤뒤, 뒤뒤앞, 뒤앞뒤, 뒤앞앞, 앞뒤뒤, 앞뒤앞, 앞앞뒤, 앞앞앞
    int t;
    cin >> t;
    while (t--) {
        for (int & i : cnt)
            i = 0;

        char a;
        cin >> a;
        char b;
        cin >> b;
        for (int i = 2; i < 40; i++) {
            char c;
            cin >> c;
            if (a == 'T' && b == 'T' && c == 'T')
                cnt[0]++;
            else if (a == 'T' && b == 'T' && c == 'H')
                cnt[1]++;
            else if (a == 'T' && b == 'H' && c == 'T')
                cnt[2]++;
            else if (a == 'T' && b == 'H' && c == 'H')
                cnt[3]++;
            else if (a == 'H' && b == 'T' && c == 'T')
                cnt[4]++;
            else if (a == 'H' && b == 'T' && c == 'H')
                cnt[5]++;
            else if (a == 'H' && b == 'H' && c == 'T')
                cnt[6]++;
            else if (a == 'H' && b == 'H' && c == 'H')
                cnt[7]++;
            a = b;
            b = c;
        }
        for (int & i : cnt) {
            cout << i << " ";
        }
        cout << "\n";
    }
}