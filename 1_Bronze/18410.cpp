#include <iostream>
#include <queue>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  queue<int> A, B;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    A.push(num);
  }
  for (int i = 0; i < m; i++) {
    int num;
    cin >> num;
    B.push(num);
  }

  vector<int> C;
  while (!A.empty() || !B.empty()) {
    queue<int>& select = (A.empty() ? B : (B.empty() ? A : (A.front() <= B.front() ? A : B)));
    C.push_back(select.front());
    select.pop();
  }
  for (auto& i : C) {
    cout << i << "\n";
  }
}