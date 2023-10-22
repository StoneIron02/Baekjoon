#include <iostream>
#include <map>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    map<string, string> map;
    map.insert({"CU", "see you"});
    map.insert({":-)", "I’m happy"});
    map.insert({":-(", "I’m unhappy"});
    map.insert({";-)", "wink"});
    map.insert({":-P", "stick out my tongue"});
    map.insert({"(~.~)", "sleepy"});
    map.insert({"TA", "totally awesome"});
    map.insert({"CCC", "Canadian Computing Competition"});
    map.insert({"CUZ", "because"});
    map.insert({"TY", "thank-you"});
    map.insert({"YW", "you’re welcome"});
    map.insert({"TTYL", "talk to you later"});

    while (true) {
        string str;
        cin >> str;
        if (map[str] != "")
            cout << map[str] << "\n";
        else
            cout << str << "\n";

        if (str == "TTYL") break;
    }
}