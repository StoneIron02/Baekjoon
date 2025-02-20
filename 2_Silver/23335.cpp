#include <iostream>
#include <vector>

using namespace std;

int calc(int n) {
  if (n == 1) return 0;

  int sum = 1;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      sum += i;
      if (i != n / i) {
        sum += n / i;
      }
    }
  }
  return sum;
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  vector<int> numbers(T);
  for (int i = 0; i < T; i++) {
    cin >> numbers[i];
  }

  for (int i = 0; i < T; i++) {
    int sum = calc(numbers[i]);
    if (sum > numbers[i]) {
      cout << "abundant\n";
    } else if (sum < numbers[i]) {
      cout << "deficient\n";
    } else {
      cout << "perfect\n";
    }
  }

}