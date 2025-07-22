#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool check(int n) {
  if (n < 2) return false;
  if (n == 2) return true;
  if (n % 2 == 0) return false;
  int root = sqrt(n);
  for (int i = 3; i <= root; i += 2) {
    if (n % i == 0) return false;
  }
  return true;
}

int get_next(int n) {
  while (!check(n)) {
    ++n;
  }
  return n;
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  string tmp; getline(cin, tmp);

  while (T--) {
    string line;
    getline(cin, line);

    vector<int> arr;
    int num = 0;
    for (char c : line + " ") {
      if (c == ' ') {
        arr.push_back(num);
        num = 0;
      } else {
        num = num * 10 + (c - '0');
      }
    }

    long long sum = 0;
    for (int val : arr) {
      sum += get_next(val);
    }
    cout << sum << "\n";
  }
}