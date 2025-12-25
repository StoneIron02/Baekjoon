#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int Q;
  cin >> Q;
  vector<string> stk;
  stk.reserve(Q);

  for (int i = 0; i < Q; ++i) {
    string s;
    cin >> s;
    if (s == "READ") {
      cout << stk.back() << '\n';
      stk.pop_back();
    } else {
      stk.push_back(s);
    }
  }
}
