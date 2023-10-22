#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string str;
    while (getline(cin, str)) {
        for (char c : str) {
            switch (c) {
                case 'e':
                    c = 'i';
                    break;
                case 'i':
                    c = 'e';
                    break;
                case 'E':
                    c = 'I';
                    break;
                case 'I':
                    c = 'E';
                    break;
            }
            cout << c;
        }
        cout << "\n";
    }
}