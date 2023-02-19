#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string str;
    cin >> str;
    regex reg("(100+1+|01)+");
    if (regex_match(str, reg))
        cout << "SUBMARINE\n";
    else
        cout << "NOISE\n";
}