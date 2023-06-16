#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

double area(vector<pair<int, int>>& pos) {
    int n = pos.size();
    double A = 0;

    for (int i = 0; i < n; i++) {
        pair<int, int> a = pos[i];
        pair<int, int> b = pos[(i + 1) % n];
        A += (double)a.first * b.second - (double)b.first * a.second;
    }
    A /= 2;
    return abs(A);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<pair<int, int>> pos;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        pos.emplace_back(x, y);
    }
    cout << fixed << setprecision(1) << area(pos);
}