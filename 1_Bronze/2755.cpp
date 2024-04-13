#include <iostream>
#include <unordered_map>
#include <iomanip>

using namespace std;

unordered_map<string, double> score = {
    {"A+", 4.3},
    {"A0", 4.0},
    {"A-", 3.7},
    {"B+", 3.3},
    {"B0", 3.0},
    {"B-", 2.7},
    {"C+", 2.3},
    {"C0", 2.0},
    {"C-", 1.7},
    {"D+", 1.3},
    {"D0", 1.0},
    {"D-", 0.7},
    {"F", 0.0}
};

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  double sum = 0;
  double wSum = 0;
  while (n--) {
    string name;
    int w;
    string str;
    cin >> name >> w >> str;
    sum += w * score[str];
    wSum += w;
  }
  cout << fixed << setprecision(2) << (sum / wSum) + 0.000000000001;
}