#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    if (n * 100 >= m)
        cout << "Yes";
    else
        cout << "No";
}