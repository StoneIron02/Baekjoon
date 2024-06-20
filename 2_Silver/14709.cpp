#include <iostream>
#include <set>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  set<pair<int, int>> s;
  int n;
  cin >> n;
  while (n--) {
    int a, b;
    cin >> a >> b;
    if (a > b) {
      int tmp = a;
      a = b;
      b = tmp;
    }
    s.insert({a, b});
  }
  if (s.find({1, 3}) != s.end() &&
      s.find({1, 4}) != s.end() &&
      s.find({3, 4}) != s.end() &&
      s.size() == 3
      ) {
    cout << "Wa-pa-pa-pa-pa-pa-pow!";
  } else {
    cout << "Woof-meow-tweet-squeek";
  }
}