#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int count = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char c;
            c = cin.get();
            if (c == 'F' && (i + j) % 2 == 0)
                count++;
        }
        cin.ignore();
    }
    cout << count;
}