#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N, K;
  cin >> N >> K;

  int count = 0;
  string k_str = to_string(K);

  for (int h = 0; h <= N; h++) {
    for (int m = 0; m < 60; m++) {
      for (int s = 0; s < 60; s++) {
        string str_h = to_string(h);
        if (str_h.size() == 1) str_h = "0" + str_h;

        string str_m = to_string(m);
        if (str_m.size() == 1) str_m = "0" + str_m;

        string str_s = to_string(s);
        if (str_s.size() == 1) str_s = "0" + str_s;

        string time_str = str_h + str_m + str_s;
        if (time_str.find(k_str) != string::npos) {
          count++;
        }
      }
    }
  }

  cout << count << endl;
}