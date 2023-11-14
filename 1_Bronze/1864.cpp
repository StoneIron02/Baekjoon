#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    unordered_map<char, int> charToInt;
    charToInt.insert({'-', 0});
    charToInt.insert({'\\', 1});
    charToInt.insert({'(', 2});
    charToInt.insert({'@', 3});
    charToInt.insert({'?', 4});
    charToInt.insert({'>', 5});
    charToInt.insert({'&', 6});
    charToInt.insert({'%', 7});
    charToInt.insert({'/', -1});

    string str;
    while (cin >> str) {
        if (str == "#") break;
        long long num = 0;
        for (char c : str) {
            num *= 8;
            num += charToInt[c];
        }
        cout << num << "\n";
    }
}