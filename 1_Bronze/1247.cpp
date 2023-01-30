#include <iostream>
#include <climits>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    for (int i = 0; i < 3; i++) {
        int n;
        cin >> n;

        int OF = 0;
        long long sum = 0;
        for (int j = 0; j < n; j++) {
            long long num;
            cin >> num;

            if (num > 0 && sum > 0 && num > LLONG_MAX - sum)
                OF++;
            if (num < 0 && sum < 0 && num < LLONG_MIN - sum)
                OF--;

            sum += num;
        }
        if (OF == 0) {
            if (sum == 0) cout << "0\n";
            else cout << (sum > 0 ? "+\n" : "-\n");
        }
        else {
            cout << (OF > 0 ? "+\n" : "-\n");
        }
    }

}