#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string board;
    cin >> board;
    string result;

    int i = 0;
    while (i < board.size()) {
        if (board[i] == '.') {
            result += '.';
            i++;
            continue;
        }

        if (board[i] == 'X' && board[i + 1] == 'X' && board[i + 2] == 'X' && board[i + 3] == 'X') {
            result += "AAAA";
            i += 4;
        } else if (board[i] == 'X' && board[i + 1] == 'X') {
            result += "BB";
            i += 2;
        } else {
            cout << -1;
            return 0;
        }
    }

    cout << result;
}