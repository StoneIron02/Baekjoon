#include <iostream>
#include <cmath>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    for (char& c : str) {
      if (c == '0' || c == '6') {
        c = '9';
      }
    }
    int score = stoi(str);
    score = min(score, 100);
    sum += score;
  }
  int e = round((double)sum / n);
  cout << e;
}