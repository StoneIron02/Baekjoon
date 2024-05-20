#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int s1, s2;
  cin >> s1 >> s2;
  for (int i = 0; i < s1; i++) {
    int a, b;
    cin >> a >> b;
    if (a != b) {
      cout << "Wrong Answer";
      exit(0);
    }
  }
  for (int i = 0; i < s2; i++) {
    int a, b;
    cin >> a >> b;
    if (a != b) {
      cout << "Why Wrong!!!";
      exit(0);
    }
  }
  cout << "Accepted";
}