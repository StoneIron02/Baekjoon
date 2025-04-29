#include <iostream>
#include <queue>
#include <tuple>
#include <set>
using namespace std;

set<tuple<int, int, int>> visited;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int A, B, C;
  cin >> A >> B >> C;
  queue<tuple<int, int, int>> que;
  que.emplace(A, B, C);
  while (!que.empty()) {
    auto [a, b, c] = que.front();
    que.pop();

    if (a == b && b == c && c == a) {
      cout << 1;
      return 0;
    }

    // a, b
    if (a < b) {
      int newA = a + a;
      int newB = b - a;
      int newC = c;
      if (visited.find({newA, newB, newC}) == visited.end()) {
        visited.insert({newA, newB, newC});
        que.emplace(newA, newB, newC);
      }
    }
    if (a > b) {
      int newA = a - b;
      int newB = b + b;
      int newC = c;
      if (visited.find({newA, newB, newC}) == visited.end()) {
        visited.insert({newA, newB, newC});
        que.emplace(newA, newB, newC);
      }
    }

    // b, c
    if (b < c) {
      int newA = a;
      int newB = b + b;
      int newC = c - b;
      if (visited.find({newA, newB, newC}) == visited.end()) {
        visited.insert({newA, newB, newC});
        que.emplace(newA, newB, newC);
      }
    }
    if (b > c) {
      int newA = a;
      int newB = b - c;
      int newC = c + c;
      if (visited.find({newA, newB, newC}) == visited.end()) {
        visited.insert({newA, newB, newC});
        que.emplace(newA, newB, newC);
      }
    }

    // c, a
    if (c < a) {
      int newA = a - c;
      int newB = b;
      int newC = c + c;
      if (visited.find({newA, newB, newC}) == visited.end()) {
        visited.insert({newA, newB, newC});
        que.emplace(newA, newB, newC);
      }
    }
    if (c > a) {
      int newA = a + a;
      int newB = b;
      int newC = c - a;
      if (visited.find({newA, newB, newC}) == visited.end()) {
        visited.insert({newA, newB, newC});
        que.emplace(newA, newB, newC);
      }
    }
  }

  cout << 0;
}
