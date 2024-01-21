#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<long long> vec;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        reverse(str.begin(), str.end());
        vec.push_back(stoll(str));
    }
    sort(vec.begin(), vec.end());
    for (auto i : vec) {
        cout << i << "\n";
    }
}