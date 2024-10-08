#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n;
  cin >> n;
  bool isFirst = true;
  int first;
  while (n--) {
    int num;
    cin >> num;
    if (isFirst) {
      first = num;
      isFirst = false;
    }
    else {
      if (num % first == 0) {
        cout << num << "\n";
        isFirst = true;
      }
    }
  }
}
