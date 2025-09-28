#include <iostream>
using namespace std;

char arr[2005];
long long arrx[2005], arry[2005];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
    int N;
    long long K;
    cin >> N >> K;
    string S;
    cin >> S;
    for (int i = 0; i < N; ++i) {
        arr[i] = S[i];
    }

    long long x = 0, y = 0;
    for (int i = 0; i < N; ++i) {
        if (arr[i] == 'U') { y += 1; }
        else if (arr[i] == 'D') { y -= 1; }
        else if (arr[i] == 'L') { x -= 1; }
        else { x += 1; }
        arrx[i + 1] = x;
        arry[i + 1] = y;
    }

    string res = "NO";

    for (int i = 1; i <= N; ++i) {
        if (arrx[i] == 0 && arry[i] == 0) {
            res = "YES";
            break;
        }
    }

    if (res == "NO") {
        long long dx = arrx[N], dy = arry[N];

        if (dx == 0 && dy == 0) {
        } else {
            for (int i = 1; i <= N; ++i) {
                long long px = arrx[i], py = arry[i];

                bool ok = false;
                long long t = -1;

                if (dx == 0 && dy != 0) {
                    if (px == 0 && ((-py) % dy == 0)) {
                        t = (-py) / dy;
                        ok = true;
                    }
                } else if (dy == 0 && dx != 0) {
                    if (py == 0 && ((-px) % dx == 0)) {
                        t = (-px) / dx;
                        ok = true;
                    }
                } else if (dx != 0 && dy != 0) {
                    if (((-px) % dx == 0)) {
                        long long tt = (-px) / dx;
                        if (dy * tt == -py) {
                            t = tt;
                            ok = true;
                        }
                    }
                }

                if (ok && t >= 0 && t <= K - 1) {
                    res = "YES";
                    break;
                }
            }
        }
    }

    cout << res << '\n';
}