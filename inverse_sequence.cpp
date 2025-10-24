#include <bits/stdc++.h>
using namespace std;
using ll = long long;

long long reverse_digits_math(long long x) {
    if (x == 0) return 0;
    bool neg = x < 0;
    unsigned long long y = (neg ? -x : x);
    unsigned long long rev = 0;
    while (y > 0) {
        rev = rev * 10 + (y % 10);
        y /= 10;
    }
    return neg ? - (long long)rev : (long long)rev;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        long long v; cin >> v;
        long long val;
        // ubah ke "if (i % 2 == 1)" kalau dosen pakai indeks 1-based
        if (i % 2 == 0) val = reverse_digits_math(v);
        else val = v;
        sum += val;
    }
    cout << sum << '\n';
}
