#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int T;
  cin >> T;
  if (T == 1) {
    long long A, B;
    cin >> A >> B;
    long long sum = A + B;
    string str(13, 'a');
    for (int i = 12; i >= 0; i--) {
      str[i] = static_cast<char>('a' + sum % 26);
      sum /= 26;
    }
    cout << str;
  } else {
    string str;
    cin >> str;
    long long sum = 0;
    for (char c : str) {
      sum = sum * 26 + (c - 'a');
    }
    cout << sum;
  }
}
