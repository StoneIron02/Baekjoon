#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  while (n--) {
    int id, s1, s2, s3;
    cin >> id >> s1 >> s2 >> s3;
    int sum = s1 + s2 + s3;
    cout << id << " " << sum << " ";
    if (sum >= 55 && s1 >= 35 * 0.3 && s2 >= 25 * 0.3 && s3 >= 40 * 0.3) {
      cout << "PASS\n";
    }
    else {
      cout << "FAIL\n";
    }
  }
}