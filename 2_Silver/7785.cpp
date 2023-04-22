#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    set<string> in;
    for (int i = 0; i < n; i++) {
        string name;
        string what;
        cin >> name >> what;
        if (what == "enter")
            in.insert(name);
        else
            in.erase(name);
    }

    for (auto p = in.rbegin(); p != in.rend(); p++) {
        cout << *p << "\n";
    }

}