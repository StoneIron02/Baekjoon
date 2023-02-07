#include <iostream>
#include <string>
#include <stack>

using namespace std;

struct package {
    int repeat;
    int cnt;
    package(int repeat, int cnt) : repeat(repeat), cnt(cnt) {};
};

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string str;
    cin >> str;
    stack<package> stack;
    int cur_cnt = 0;
    for (int i = 0; i < str.size(); i++) {
        char c = str[i];
        if (c == '(') {
            cur_cnt--;
            package p(str[i - 1] - '0', cur_cnt);
            stack.push(p);
            cur_cnt = 0;
        } else if (c == ')') {
            package p = stack.top();
            stack.pop();
            cur_cnt = cur_cnt * p.repeat + p.cnt;
        } else {
            cur_cnt++;
        }
    }

    cout << cur_cnt;
}