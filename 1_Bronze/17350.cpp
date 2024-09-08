#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  bool flag = false;
  while (n--) {
    string name;
    cin >> name;
    if (name == "anj") {
      flag = true;
    }
  }

  cout << (flag ? "뭐야;" : "뭐야?");
}