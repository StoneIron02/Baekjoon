#include <iostream>
#include <vector>

using namespace std;

vector<int> KMPFailure(const string& str) {
    int m = str.length();
    vector<int> failure(m, 0);

    int j = 0;
    for (int i = 1; i < m; ++i) {
        while (j > 0 && str[i] != str[j]) {
            j = failure[j - 1];
        }

        if (str[i] == str[j]) {
            failure[i] = j + 1;
            ++j;
        }
    }

    return failure;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int l;
    cin >> l;
    string str;
    cin >> str;
    int m = str.size();
    vector<int> f = KMPFailure(str);
    cout << (m - f[m - 1]);
}