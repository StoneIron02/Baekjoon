#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

constexpr double PI = 3.1415927;
constexpr double INCHES_PER_MILE = 12 * 5280;
constexpr double SECONDS_PER_HOUR = 3600;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  double diameter, time;
  int revolutions;
  int cnt = 1;

  while (cin >> diameter >> revolutions >> time) {
    if (revolutions == 0) break;

    double distance = (PI * diameter * revolutions) / INCHES_PER_MILE;

    double hour = time / SECONDS_PER_HOUR;
    double speed = distance / hour;

    cout << fixed << setprecision(2) << "Trip #" << cnt << ": " << distance << " " << speed << endl;
    ++cnt;
  }
}