#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int A, B, C;
  cin >> A >> B >> C;
  cout << A + B - C << "\n";
  cout << stoi(to_string(A) + to_string(B)) - C;
}