#include <iostream>
#include <stack>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int r, c;
    cin >> r >> c;
    cin.ignore();
    for (int i = 0; i < r; i++) {
        stack<char> stack;
        for (int j = 0; j < c; j++) {
            stack.push(cin.get());
        }
        while (!stack.empty()) {
            cout << stack.top();
            stack.pop();
        }
        cin.ignore();
        cout << "\n";
    }
}