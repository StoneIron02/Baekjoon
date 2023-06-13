#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int antenna, eyes;
    cin >> antenna >> eyes;

    if (antenna >= 3 && eyes <= 4) {
        cout << "TroyMartian\n";
    }
    if (antenna <= 6 && eyes >= 2) {
        cout << "VladSaturnian\n";
    }
    if (antenna <= 2 && eyes <= 3) {
        cout << "GraemeMercurian\n";
    }
}