#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string S;
  cin >> S;

  int zero_cnt = 0, one_cnt = 0;
  for (char c : S) {
    if (c == '0') zero_cnt++;
    else one_cnt++;
  }

  int remove_zero = zero_cnt / 2;
  int remove_one = one_cnt / 2;

  string result = "";

  for (char c : S) {
    if (c == '1' && remove_one > 0) {
      remove_one--;
      continue;
    }
    result += c;
  }

  for (int i = result.size() - 1; i >= 0 && remove_zero > 0; i--) {
    if (result[i] == '0') {
      result.erase(i, 1);
      remove_zero--;
    }
  }

  cout << result << "\n";
}