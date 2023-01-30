#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> calls(n);
    for (int i = 0; i < n; i++)
        cin >> calls[i];

    int sumY = 0, sumM = 0;
    for (int i = 0; i < n; i++) {
        int time = calls[i];
        sumY += 10 * (time / 30 + 1);
        sumM += 15 * (time / 60 + 1);
    }

    if (sumY == sumM)
        cout << "Y M " << sumY;
    else if (sumY < sumM)
        cout << "Y " << sumY;
    else
        cout << "M " << sumM;
}