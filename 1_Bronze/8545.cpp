#include <iostream>
#include <stack>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    stack<char> stack;
    string str;
    cin >> str;
    for (char c : str) {
        stack.push(c);
    }
    while (!stack.empty()) {
        char c = stack.top();
        cout << c;
        stack.pop();
    }
}