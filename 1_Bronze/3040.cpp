#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr(9);
string sel = "001111111";

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  for (int i = 0; i < 9; i++) {
    cin >> arr[i];
  }

  do {
    int sum = 0;
    for (int i = 0; i < 9; i++) {
      if (sel[i] == '1') sum += arr[i];
    }
    if (sum == 100) {
      for (int i = 0; i < 9; i++) {
        if (sel[i] == '1') cout << arr[i] << "\n";
      }
      exit(0);
    }
  } while (next_permutation(sel.begin(), sel.end()));
}