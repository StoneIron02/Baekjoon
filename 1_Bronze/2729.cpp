#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        if (a.size() < b.size()) {
            string tmp = a;
            a = b;
            b = tmp;
        }

        int i = 0;
        int before = 0;
        string result = "";
        for (; i < b.size(); i++) {
            int ai = a[a.size() - 1 - i] - '0';
            int bi = b[b.size() - 1 - i] - '0';
            int next = before + ai + bi;

            if (next == 0) {
                before = 0;
                result = "0" + result;
            }
            if (next == 1) {
                before = 0;
                result = "1" + result;
            }
            if (next == 2) {
                before = 1;
                result = "0" + result;
            }
            if (next == 3) {
                before = 1;
                result = "1" + result;
            }
        }

        for (; i < a.size(); i++) {
            int ai = a[a.size() - 1 - i] - '0';
            int next = before + ai;

            if (next == 0) {
                before = 0;
                result = "0" + result;
            }
            if (next == 1) {
                before = 0;
                result = "1" + result;
            }
            if (next == 2) {
                before = 1;
                result = "0" + result;
            }
            if (next == 3) {
                before = 1;
                result = "1" + result;
            }
        }

        if (before == 1) {
            result = "1" + result;
        }

        while (result[0] == '0') {
            result = result.substr(1);
        }
        if (result == "")
            result = "0";

        cout << result << "\n";
    }
}