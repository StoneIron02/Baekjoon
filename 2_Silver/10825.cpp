#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct info {
  string name;
  int kor;
  int eng;
  int mat;
};

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<info> arr;
  for (int i = 0; i < N; i++) {
    string name;
    int kor, eng, mat;
    cin >> name >> kor >> eng >> mat;
    arr.push_back({name, kor, eng, mat});
  }

  sort(arr.begin(), arr.end(), [](const info& l, const info& r) {
    if (l.kor != r.kor) {
      return l.kor > r.kor;
    }
    if (l.eng != r.eng) {
      return l.eng < r.eng;
    }
    if (l.mat != r.mat) {
      return l.mat > r.mat;
    }
    return l.name < r.name;
  });

  for (auto& i : arr) {
    cout << i.name << "\n";
  }
}