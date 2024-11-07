#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

long long Power(long long a, long long n) {
    if (n == 0)
        return 1;
    if (n & 1)
        return a * (Power(a, n - 1) % MOD) % MOD;
    
    long long t = Power(a, n / 2) % MOD;
    return t * t % MOD;
}

int main() {
    int n, k;
    cin >> n >> k;

    if (k > n) {
        cout << 0 << endl;
        return 0;
    }
    if (k == 0) {
        cout << 1 << endl;
        return 0;
    }

    vector <long long> F(n+1, 1);
    for (int i = 1; i <= n; i++) {
        F[i] = (F[i - 1] * i) % MOD;
    }
    cout << F[n] * Power(F[k] * F[n - k] % MOD, MOD - 2) % MOD;
    return 0;
}
