#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string S;
  cin >> S;

  string yonsei = "YONSEI";
  string korea = "KOREA";

  int yonseiIndex = 0, koreaIndex = 0;
  int sIndexY = 0, sIndexK = 0;

  while (sIndexY < S.size() && yonseiIndex < yonsei.size()) {
    if (S[sIndexY] == yonsei[yonseiIndex]) {
      yonseiIndex++;
    }
    sIndexY++;
  }

  while (sIndexK < S.size() && koreaIndex < korea.size()) {
    if (S[sIndexK] == korea[koreaIndex]) {
      koreaIndex++;
    }
    sIndexK++;
  }

  if (sIndexY <= sIndexK) {
    cout << "YONSEI" << endl;
  } else {
    cout << "KOREA" << endl;
  }
}