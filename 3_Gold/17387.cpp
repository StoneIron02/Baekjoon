#include <iostream>

using namespace std;

long long CCW(pair<int, int> A, pair<int, int> B, pair<int, int> C) {
    long long result = (long long)(B.first - A.first) * (C.second - A.second)
            - (long long)(C.first - A.first) * (B.second - A.second);
    return result;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int x1, y1, x2, y2;
    int x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    pair<int, int> p1(x1, y1);
    pair<int, int> p2(x2, y2);
    pair<int, int> p3(x3, y3);
    pair<int, int> p4(x4, y4);

    // check p1p2 -> p3, p4
    long long p3ccw = CCW(p1, p2, p3);
    long long p4ccw = CCW(p1, p2, p4);
    if (p3ccw > 0 && p4ccw > 0) {
        cout << 0;
        return 0;
    }
    if (p3ccw < 0 && p4ccw < 0) {
        cout << 0;
        return 0;
    }

    // check p3p4 -> p1, p2
    long long p1ccw = CCW(p3, p4, p1);
    long long p2ccw = CCW(p3, p4, p2);
    if (p1ccw > 0 && p2ccw > 0) {
        cout << 0;
        return 0;
    }
    if (p1ccw < 0 && p2ccw < 0) {
        cout << 0;
        return 0;
    }

    // 겹침
    if (p1ccw == 0 && p2ccw == 0 && p3ccw == 0 && p4ccw == 0) {
        if (p1 > p2) swap(p1, p2);
        if (p3 > p4) swap(p3, p4);

        if (p3 <= p2 && p1 <= p4)
            cout << 1;
        else
            cout << 0;
        return 0;
    }

    cout << 1;
}