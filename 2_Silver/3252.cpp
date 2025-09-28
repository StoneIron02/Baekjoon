#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;

  vector<pair<double,int>> round1(N);

  double firstTime;
  cin >> firstTime;
  round1[0] = {firstTime, 1};

  double bestTime = firstTime;
  int leader = 0;

  for (int i = 1; i < N; i++) {
    string diffStr;
    cin >> diffStr;
    double diff = stod(diffStr.substr(1));
    double newTime;
    if (diffStr[0] == '+') {
      newTime = round1[leader].first + diff;
    } else { // '-'
      newTime = round1[leader].first - diff;
    }
    round1[i] = {newTime, i + 1};

    if (newTime < bestTime) {
      bestTime = newTime;
      leader = i;
    }
  }

  sort(round1.begin(), round1.end());
  vector<pair<double,int>> qualified(round1.begin(), round1.begin() + M);
  reverse(qualified.begin(), qualified.end());

  vector<pair<double,int>> finalResults(M);

  double firstTotal;
  cin >> firstTotal;
  finalResults[0] = {firstTotal, qualified[0].second};

  bestTime = firstTotal;
  leader = 0;

  for (int i = 1; i < M; i++) {
    string diffStr;
    cin >> diffStr;

    double diff = stod(diffStr.substr(1));
    double newTime;
    if (diffStr[0] == '+') {
      newTime = finalResults[leader].first + diff;
    } else {
      newTime = finalResults[leader].first - diff;
    }
    finalResults[i] = {newTime, qualified[i].second};

    if (newTime < bestTime) {
      bestTime = newTime;
      leader = i;
    }
  }

  sort(finalResults.begin(), finalResults.end());

  cout << finalResults[0].second << "\n"
       << finalResults[1].second << "\n"
       << finalResults[2].second << "\n";
}