#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string str = "WelcomeToSMUPC";
  int n;
  cin >> n;
  n--;
  n = n % 14;
  cout << str[n];
}