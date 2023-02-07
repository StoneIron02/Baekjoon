#include <iostream>
#include <stack>

using namespace std;

struct tower {
    int no;
    int height;
    tower(int no, int height) : no(no), height(height) {};
};

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    stack<tower> stack;
    for (int i = 1; i <= n; i++) {
        int height;
        cin >> height;
        tower t(i, height);
        while (!stack.empty() && stack.top().height < t.height)
            stack.pop();
        if (stack.empty())
            cout << "0 ";
        else
            cout << stack.top().no << " ";
        stack.push(t);
    }
}