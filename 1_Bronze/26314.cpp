#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n;
  cin >> n;
  string str;
  for (int i = 0; i < n; i++) {
    cin >> str;
    int vowel = 0, consonant = 0;
    for (char c : str) {
      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') vowel++;
      else consonant++;
    }
    cout << str << '\n';
    cout << (vowel > consonant ? 1 : 0) << '\n';
  }
}