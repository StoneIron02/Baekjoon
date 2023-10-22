#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int score = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        bool isCorrect;
        cin >> isCorrect;
        if (isCorrect) {
            score++;
            sum += score;
        } else {
            score = 0;
        }
    }
    cout << sum;
}