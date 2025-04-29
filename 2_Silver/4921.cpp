#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  unordered_set<int> canNext[9];
  canNext[1] = {4, 5};
  canNext[2] = {};
  canNext[3] = {4, 5};
  canNext[4] = {2, 3};
  canNext[5] = {8};
  canNext[6] = {2, 3};
  canNext[7] = {8};
  canNext[8] = {6, 7};

  string str;
  int i = 0;
  while (++i) {
    cin >> str;
    if (str == "0") break;

    if (str.front() != '1' || str.back() != '2') {
      cout << i << ". " << "NOT\n";
      continue;
    }

    bool flag = true;
    for (int j = 0; j < str.size() - 1; j++) {
      if (canNext[str[j] - '0'].find(str[j + 1] - '0') == canNext[str[j] - '0'].end()) {
        flag = false;
        break;
      }
    }
    if (!flag) {
      cout << i << ". " << "NOT\n";
      continue;
    }

    cout << i << ". " << "VALID\n";
  }
}
