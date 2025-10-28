#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string S;
  cin >> S;
  double sum = 0;
  int cnt = 0;

  for (int i = 0; i < S.size(); ) {
    if (i + 1 < S.size() && S[i+1] == '+') {
      string grade = S.substr(i, 2);
      if (grade == "A+") sum += 4.5;
      else if (grade == "B+") sum += 3.5;
      else if (grade == "C+") sum += 2.5;
      else if (grade == "D+") sum += 1.5;
      cnt++;
      i += 2;
    } else {
      char grade = S[i];
      if (grade == 'A') sum += 4;
      else if (grade == 'B') sum += 3;
      else if (grade == 'C') sum += 2;
      else if (grade == 'D') sum += 1;
      cnt++;
      i++;
    }
  }

  cout << fixed << setprecision(5) << sum / cnt;
}