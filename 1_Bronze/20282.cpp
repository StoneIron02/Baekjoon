#include <iostream>
#include <vector>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int C;
  cin >> C;

  vector<int> boxes(C);
  for(int i = 0; i < C; i++) {
    cin >> boxes[i];
  }

  int current_sum = 100;
  int max_sum = 100;

  for(int i = 0; i < C; i++) {
    current_sum += boxes[i];
    if(current_sum > max_sum) {
      max_sum = current_sum;
    }
  }
  cout << max_sum << "\n";
}