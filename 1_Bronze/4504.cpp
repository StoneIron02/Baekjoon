#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  int num;
  while (true) {
    cin >> num;
    if (num == 0) break;

    cout << num << " is ";
    cout << (num % n == 0 ? "" : "NOT ");
    cout << "a multiple of " << n << ".\n";
  }
}