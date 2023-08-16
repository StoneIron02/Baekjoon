#include <iostream>

using namespace std;

bool contain(int num, int l) {
    while (num > 0) {
        if (num % 10 == l)
            return true;
        num /= 10;
    }
    return false;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, l;
    cin >> n >> l;
    int i = 1;
    while (n > 0) {
        if (!contain(i, l)) {
            n--;
        }
        i++;
    }
    i--;
    cout << i;
}