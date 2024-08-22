#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n;
  cin >> n;
  unordered_map<string, int> scores;
  for (int i = 0; i < n; i++) {
    string name;
    cin >> name;
    scores.insert({name, 0});
  }
  int m;
  cin >> m;
  cin.ignore();
  int beforeScore1 = 0, beforeScore2 = 0;
  while (m--) {
    string score1Str, score2Str, name;
    int score1, score2;
    getline(cin, score1Str, ':');
    getline(cin, score2Str, ' ');
    getline(cin, name);
    score1 = stoi(score1Str);
    score2 = stoi(score2Str);
    if (score1 != beforeScore1) {
      scores[name] += score1 - beforeScore1;
    }
    if (score2 != beforeScore2) {
      scores[name] += score2 - beforeScore2;
    }
    beforeScore1 = score1;
    beforeScore2 = score2;
  }
  auto maxVal = max_element(scores.begin(), scores.end(),
    [](const pair<string, int>& a, const pair<string, int>& b) {
      return a.second < b.second;
    }
  );
  cout << maxVal->first << " " << maxVal->second;
}
