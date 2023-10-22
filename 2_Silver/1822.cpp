#include <iostream>
#include <set>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int nA, nB;
    cin >> nA >> nB;

    set<int> A;
    set<int> B;
    for (int i = 0; i < nA; i++) {
        int num;
        cin >> num;
        A.insert(num);
    }
    for (int i = 0; i < nB; i++) {
        int num;
        cin >> num;
        auto pos = A.find(num);
        if (pos != A.end()) {
            A.erase(pos);
        }
    }

    cout << A.size() << "\n";
    if (A.empty()) {
        return 0;
    }
    for (auto i : A) {
        cout << i << " ";
    }
}