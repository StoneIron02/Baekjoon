#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string str;
    cin >> str;
    if (str == "SONGDO")
        cout << "HIGHSCHOOL";
    else if (str == "CODE")
        cout << "MASTER";
    else if (str == "2023")
        cout << "0611";
    else
        cout << "CONTEST";
}