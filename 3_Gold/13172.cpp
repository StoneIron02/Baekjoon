#include <iostream>
#include <numeric>

using namespace std;

int M;
int N[10000];
int S[10000];

int modPow(long long base, int exponent, int modulus) {
    if (modulus == 1)
        return 0;

    int result = 1;
    base = base % modulus;

    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;

        exponent = exponent >> 1;

        base = (base * base) % modulus;
    }

    return result;
}

int modInverse(int a, int m) {
    int inverse = modPow(a, m - 2, m);

    return inverse;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> M;
    for (int i = 0; i < M; i++)
        cin >> N[i] >> S[i];

    long long sum = 0;
    for (int i = 0; i < M; i++) {
        int g = gcd(S[i], N[i]);
        S[i] /= g;
        N[i] /= g;
        long long N_rev = modInverse(N[i], 1'000'000'007);
        sum += N_rev * S[i] % 1'000'000'007;
    }
    sum %= 1'000'000'007;

    cout << sum;
}