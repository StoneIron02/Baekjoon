#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<long long> fib;
unordered_set<long long> fib_set;

void generateFibonacci(long long maxVal) {
  fib.push_back(1);
  fib.push_back(1);
  fib_set.insert(1);

  while (true) {
    long long next = fib[fib.size()-1] + fib[fib.size()-2];
    if (next > maxVal) break;
    fib.push_back(next);
    fib_set.insert(next);
  }
}

bool canSum(int k, long long x) {
  if (k == 1) {
    return fib_set.count(x) > 0;
  } else if (k == 2) {
    for (long long num : fib) {
      if (fib_set.count(x - num)) {
        return true;
      }
    }
    return false;
  } else {
    for (long long a : fib) {
      for (long long b : fib) {
        if (fib_set.count(x - a - b)) {
          return true;
        }
      }
    }
    return false;
  }
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  generateFibonacci(1e16);

  int T;
  cin >> T;
  while (T--) {
    int k;
    long long x;
    cin >> k >> x;

    if (canSum(k, x))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}