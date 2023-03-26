#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int ball[101];
    for (int i = 1; i <= n; i++) {
        ball[i] = i;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int start, end;
        cin >> start >> end;
        int temp = ball[start];
        ball[start] = ball[end];
        ball[end] = temp;
    }

    for (int i = 1; i <= n; i++) {
        cout << ball[i] << " ";
    }
}