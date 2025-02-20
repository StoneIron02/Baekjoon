#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  unordered_map<string, string> word;
  while (N--) {
    string x, tmp, y;
    cin >> x >> tmp >> y;
    word[x] = y;
  }
  int T;
  cin >> T;
  while (T--) {
    int K;
    cin >> K;
    while (K--) {
      string str;
      cin >> str;
      if (word.find(str) != word.end()) {
        cout << word[str] << " ";
      } else {
        cout << str << " ";
      }
    }
    cout << "\n";
  }
}