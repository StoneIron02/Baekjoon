#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string str;
  cin >> str;

  int mid = str.size() / 2;
  int l_rum = 0, r_sum = 0;

  for (int i = 0; i < mid; ++i) {
    l_rum += str[i] - '0';
  }
  for (int i = mid; i < str.size(); ++i) {
    r_sum += str[i] - '0';
  }

  if (l_rum == r_sum) {
    cout << "LUCKY";
  } else {
    cout << "READY";
  }
}