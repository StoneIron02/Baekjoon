#include <iostream>
#include <set>
using namespace std;

struct entry {
  int cnt[26]{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

  explicit entry(const string& str) {
    for (char c : str) {
      cnt[c - 'a']++;
    }
  }

  bool operator<(const entry& other) const {
    for (int i = 0; i < 26; i++) {
      if (cnt[i] != other.cnt[i]) {
        return cnt[i] < other.cnt[i];
      }
    }
    return false;
  }

  bool operator==(const entry& other) const {
    for (int i = 0; i < 26; i++) {
      if (cnt[i] != other.cnt[i]) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int N;
  cin >> N;
  set<entry> st;
  while (N--) {
    string str;
    cin >> str;
    entry e(str);
    st.insert(e);
  }
  cout << st.size();
}
