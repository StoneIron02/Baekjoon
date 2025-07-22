#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  string S;
  cin >> N >> S;

  unordered_set<char> st;
  for (char& c : S) {
    st.insert(c);
  }

  cout << (st.size() >= 3 ? "Yes" : "No");
}