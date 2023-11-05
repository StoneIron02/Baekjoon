#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    for (int i = 0; i < 3; i++) {
        int hStart, mStart, sStart, hEnd, mEnd, sEnd;
        cin >> hStart >> mStart >> sStart >> hEnd >> mEnd >> sEnd;
        int start = hStart * 3600 + mStart * 60 + sStart;
        int end = hEnd * 3600 + mEnd * 60 + sEnd;
        int diff = end - start;
        int hDiff = diff / 3600;
        int mDiff = (diff % 3600) / 60;
        int sDiff = (diff % 3600) % 60;
        cout << hDiff << " " << mDiff << " " << sDiff << "\n";
    }
}