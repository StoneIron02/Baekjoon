#include <iostream>
#include <set>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  set<string> arr;
  string suit;
  int value;

  for (int i = 0; i < 51; i++) {
    cin >> suit >> value;
    arr.insert(suit + " " + to_string(value));
  }

  char suits[] = {'S', 'B', 'V', 'K'};
  for (char s : suits) {
    for (int v = 1; v <= 13; v++) {
      string card = string(1, s) + " " + to_string(v);
      if (arr.find(card) == arr.end()) {
        cout << card << endl;
        return 0;
      }
    }
  }
}