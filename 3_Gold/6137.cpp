#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<char> dq;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        dq.push_back(c);
    }
    string result;
    int i = 0, j = n - 1;
    while (i <= j) {
        if (result.size() == 80) {
            cout << result << "\n";
            result = "";
        }
        char front = dq[i];
        char back = dq[j];
        if (front < back) {
            result += front;
            i++;
        } else if (front > back) {
            result += back;
            j--;
        } else {
            if (dq.size() <= 3) {
                result += front;
                i++;
                continue;
            }
            int p = i + 1, q = j - 1;
            while (dq[p] == dq[q]) {
                p++;
                q--;
            }
            if (dq[p] < dq[q]) {
                result += front;
                i++;
            } else {
                result += back;
                j--;
            }
        }
    }
    cout << result;
}