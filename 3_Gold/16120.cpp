#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string str;
    cin >> str;
    vector<char> stack;
    for (char c : str) {
        if (c == 'P') {
            if (stack.size() >= 3) {
                if (stack[stack.size() - 1] == 'A' &&
                stack[stack.size() - 2] == 'P' &&
                stack[stack.size() - 3] == 'P') {
                    stack.pop_back();
                    stack.pop_back();
                    stack.pop_back();
                    stack.push_back('P');
                } else {
                    stack.push_back('P');
                }
            } else {
                stack.push_back('P');
            }
        } else { // A
            stack.push_back('A');
        }
    }

    if (stack.size() == 1 && stack[0] == 'P') {
        cout << "PPAP";
    } else {
        cout << "NP";
    }
}