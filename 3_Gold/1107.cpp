#include <iostream>

using namespace std;

bool deny[10];

bool isNoDeny(int num) {
    if (num == 0) {
        return !deny[0];
    }
    while (num > 0) {
        int d = num % 10;
        if (deny[d])
            return false;
        num /= 10;
    }
    return true;
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

    string numStr;
    cin >> numStr;
    int destination = stoi(numStr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        deny[num] = true;
    }

    if (destination == 100) {
        cout << 0;
        return 0;
    }
    if (n == 10) { // all deny
        cout << abs(100 - destination);
        return 0;
    }

    int cnt;
    int i = destination;
    int j = destination;
    while (true) {
        if (isNoDeny(i)) {
            cnt = to_string(i).size() + abs(i - destination);
            break;
        }
        if (isNoDeny(j)) {
            cnt = to_string(j).size() + abs(j - destination);
            break;
        }
        if (i > 0)
            i--;
        j++;
    }

    cnt = min(abs(100 - destination), cnt);
    cout << cnt;
}