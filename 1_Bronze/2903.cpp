#include <iostream>
#include <cmath>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int l = (int)pow(2, n) + 1;
    int result = (int)pow(l, 2);
    cout << result;
}