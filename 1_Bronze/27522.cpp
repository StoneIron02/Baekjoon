#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef pair<int, char> racer;

int convert(const string& str) {
  int minutes = stoi(str.substr(0, str.find(':')));
  int seconds = stoi(str.substr(str.find(':') + 1, 2));
  int milliseconds = stoi(str.substr(str.rfind(':') + 1));

  return minutes * 60 * 1000 + seconds * 1000 + milliseconds;
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  vector<racer> racers(8);
  for (int i = 0; i < 8; ++i) {
    string str;
    char team;
    cin >> str >> team;
    racers[i] = { convert(str), team };
  }

  int score[8] = {10, 8, 6, 5, 4, 3, 2, 1};

  sort(racers.begin(), racers.end(), [](const racer& a, const racer& b) {
    return a.first < b.first;
  });

  int score_red = 0, score_blue = 0;
  int res_red = 9, res_blue = 9;

  for (int i = 0; i < 8; ++i) {
    if (racers[i].second == 'R') {
      score_red += score[i];
      res_red = min(res_red, i + 1);
    } else {
      score_blue += score[i];
      res_blue = min(res_blue, i + 1);
    }
  }

  if (score_red > score_blue) {
    cout << "Red";
  } else if (score_blue > score_red) {
    cout << "Blue";
  } else {
    if (res_red < res_blue) {
      cout << "Red";
    } else {
      cout << "Blue";
    }
  }
}