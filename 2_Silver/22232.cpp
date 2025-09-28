#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

struct File {
  string fn;
  string ext;
  string orig;
  bool dup;
};

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;
  vector<string> arr(N);
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
  }

  unordered_set<string> rec;
  for (int i = 0; i < M; ++i) {
    string str;
    cin >> str;
    rec.insert(str);
  }

  vector<File> v;
  v.reserve(N);
  for (int i = 0; i < N; ++i) {
    auto& s = arr[i];
    auto pos = s.rfind('.');
    string fn = s.substr(0, pos);
    string ext = s.substr(pos + 1);
    bool dup = rec.find(ext) != rec.end();
    v.push_back({fn, ext, s, dup});
  }

  sort(v.begin(), v.end(), [](const File& a, const File& b) {
      if (a.fn != b.fn) return a.fn < b.fn;
      if (a.dup != b.dup) return a.dup > b.dup;
      if (a.ext != b.ext) return a.ext < b.ext;
      return a.orig < b.orig;
  });

  for (auto& f : v) {
    cout << f.orig << '\n';
  }
}