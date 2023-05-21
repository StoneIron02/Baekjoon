#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    map<string, string> pws;
    for (int i = 0; i < n; i++) {
        string site, pw;
        cin >> site >> pw;
        pws.insert({site, pw});
    }
    for (int i = 0; i < m; i++) {
        string site;
        cin >> site;
        cout << pws[site] << "\n";
    }
}