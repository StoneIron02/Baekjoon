#include <iostream>
#include <vector>

using namespace std;

vector<int> papers(7);

void push1(int left) {
    if (papers[1] >= left)
        papers[1] -= left;
    else
        papers[1] = 0;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    for (int i = 1; i <= 6; i++)
        cin >> papers[i];

    int numBoard = 0;

    // 6은 판을 모두 채움
    numBoard += papers[6];

    // 5는 1을 11개 넣을 수 있음
    while (papers[5] > 0) {
        numBoard++;
        papers[5]--;
        push1(11);
    }

    // 4는 2를 5개 넣을 수 있고, 남은 자리에 1을 20개 넣을 수 있음
    while (papers[4] > 0) {
        numBoard++;
        papers[4]--;
        if (papers[2] >= 5)
            papers[2] -= 5;
        else {
            int left = (5 - papers[2]) * 4;
            papers[2] = 0;
            push1(left);
        }
    }

    // 3은 넣은 개수에 따라 2를 넣을 수 있는 개수와 1을 넣을 수 있는 개수가 유동적
    while (papers[3] > 0) {
        numBoard++;
        if (papers[3] >= 4)
            papers[3] -= 4;
        else {
            int left3, left;
            if (papers[3] == 3) {
                left3 = 1;
                left = 5;
            }
            else if (papers[3] == 2) {
                left3 = 3;
                left = 6;
            }
            else {
                left3 = 5;
                left = 7;
            }
            papers[3] = 0;

            if (papers[2] >= left3)
                papers[2] -= left3;
            else {
                left += (left3 - papers[2]) * 4;
                papers[2] = 0;
            }
            push1(left);
        }
    }

    // 2
    while (papers[2] > 0) {
        numBoard++;
        if (papers[2] >= 9)
            papers[2] -= 9;
        else {
            int left = (9 - papers[2]) * 4;
            papers[2] = 0;
            push1(left);
        }
    }

    // 1
    while (papers[1] > 0) {
        numBoard++;
        papers[1] -= 36;
    }

    cout << numBoard;
}