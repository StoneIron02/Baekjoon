#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  cout << "int a;\n";
  for (int i = 1; i <= N; i++) {
    cout << "int ";
    for (int j = 1; j <= i; j++) {
      cout << '*';
    }
    cout << "ptr";
    if (i > 1) cout << i;
    cout << " = &";
    if (i == 1) cout << "a;\n";
    else if (i == 2) cout << "ptr;\n";
    else cout << "ptr" << i - 1 << ";\n";
  }
}