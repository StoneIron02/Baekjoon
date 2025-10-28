#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int N;
  cin >> N;

  unordered_map<string, int> wa_cnt;
  unordered_set<string> correct;
  for (int i = 0; i < N; ++i) {
    int id, result, mem, time, lang, code;
    string user;
    cin >> id >> user >> result >> mem >> time >> lang >> code;
    if (user == "megalusion") continue;
    if (correct.contains(user)) continue;
    if (result == 4) correct.insert(user);
    else ++wa_cnt[user];
  }

  long long correct_cnt = correct.size();
  if (correct_cnt == 0) {
    cout << 0;
    return 0;
  }

  long long total = 0;
  for (auto &u : correct) total += wa_cnt[u];

  double ans = (double)correct_cnt / (correct_cnt + total) * 100.0;
  cout << fixed << setprecision(20) << ans;
}