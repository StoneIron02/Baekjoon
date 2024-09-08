#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  while (n--) {
    string str;
    cin >> str;
    int s, e;
    cin >> s >> e;
    for (int i = 0; i < s; i++) {
      cout << str[i];
    }
    for (int i = e; i < str.size(); i++) {
      cout << str[i];
    }
    cout << "\n";
  }
}