#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, string> conv = {
    {1, "VVV딸기"},
    {2, "VV딸기V"},
    {3, "VV딸기딸기"},
    {4, "V딸기VV"},
    {5, "V딸기V딸기"},
    {6, "V딸기딸기V"},
    {7, "V딸기딸기딸기"},
    {8, "딸기VVV"},
    {9, "딸기VV딸기"},
    {10, "딸기V딸기V"},
    {11, "딸기V딸기딸기"},
    {12, "딸기딸기VV"},
    {13, "딸기딸기V딸기"},
    {14, "딸기딸기딸기V"},
    {15, "딸기딸기딸기딸기"},
    {16, "딸기딸기딸기V"},
    {17, "딸기딸기V딸기"},
    {18, "딸기딸기VV"},
    {19, "딸기V딸기딸기"},
    {20, "딸기V딸기V"},
    {21, "딸기VV딸기"},
    {22, "딸기VVV"},
    {23, "V딸기딸기딸기"},
    {24, "V딸기딸기V"},
    {25, "V딸기V딸기"},
    {26, "V딸기VV"},
    {27, "VV딸기딸기"},
    {28, "VV딸기V"}
};

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--) {
    long long N;
    cin >> N;
    int n = (N - 1) % 28 + 1;
    cout << conv[n] << "\n";
  }
}