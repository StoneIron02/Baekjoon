#include <iostream>
#include <algorithm>
using namespace std;

bool isVowel(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  long long cnt = 0;
  for (int i = 0; i < N; ++i) {
    string str;
    cin >> str;
    int noun0 = 0, noun1 = 0, verb = 0;
    for (int j = 0; j < str.size(); ++j) {
      if (j % 2 == 0) {
        noun0 += isVowel(str[j]) ? 0 : 1;
        noun1 += isVowel(str[j]) ? 1 : 0;
      }
      else {
        noun0 += isVowel(str[j]) ? 1 : 0;
        noun1 += isVowel(str[j]) ? 0 : 1;
      }
      if (!isVowel(str[j]))
        verb++;
    }
    cnt += min({noun0, noun1, verb});
  }
  cout << cnt << "\n";
}
