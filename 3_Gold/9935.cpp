#include <iostream>
#include <stack>
#include <deque>

using namespace std;

string T, P;
deque<char> result;

bool match() {
    for (int i = 0; i < P.size(); i++) {
        if (result[result.size() - P.size() + i] != P[i])
            return false;
    }
    return true;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> T >> P;
    for (char c : T) {
        result.push_back(c);
        if (result.size() < P.size()) continue;
        if (P[P.size() - 1] == c) {
            if (match()) {
                for (int i = 0; i < P.size(); i++)
                    result.pop_back();
            }
        }
    }
    if (result.empty()) {
        cout << "FRULA";
        return 0;
    }
    while (!result.empty()) {
        cout << result.front();
        result.pop_front();
    }
}