#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> make_failure_function(string P) {
    vector<int> pi;
    pi.resize(P.size());
    pi[0] = 0;
    int k = 0;
    for (int q = 1; q < P.size(); q++) {
        while (k > 0 && P[k] != P[q])
            k = pi[k - 1];
        if (P[k] == P[q])
            k += 1;
        pi[q] = k;
    }
    return pi;
}

vector<int> KMP(string T, string P) {
    vector<int> match;
    vector<int> pi = make_failure_function(P);
    int q = 0;
    for (int i = 0; i < T.size(); i++) {
        while (q > 0 && P[q] != T[i])
            q = pi[q - 1];
        if (P[q] == T[i])
            q += 1;
        if (q == P.size()) {
            match.push_back(i - (int)P.size() + 1);
            q = pi[q - 1];
        }
    }
    return match;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string T, P;
    getline(cin, T);
    getline(cin, P);
    vector<int> match = KMP(T, P);
    cout << match.size() << "\n";
    for (int i : match) {
        cout << (i + 1) << "\n";
    }
}