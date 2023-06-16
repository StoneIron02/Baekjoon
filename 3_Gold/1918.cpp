#include <iostream>
#include <stack>
#include <map>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    map<char, int> priority;
    priority.insert({'+', 1});
    priority.insert({'-', 1});
    priority.insert({'*', 2});
    priority.insert({'/', 2});
    priority.insert({'(', 3});
    priority.insert({')', 3});

    stack<char> op;

    string str;
    cin >> str;
    for (char c : str) {
        if (c >= 'A' && c <= 'Z')
            cout << c;
        else if (c == ')') {
            while (op.top() != '(') {
                cout << op.top();
                op.pop();
            }
            op.pop();
        } else {
            int p = priority[c];
            while (!op.empty() && op.top() != '(' && priority[op.top()] >= p) {
                cout << op.top();
                op.pop();
            }
            op.push(c);
        }
    }
    while (!op.empty()) {
        cout << op.top();
        op.pop();
    }
}