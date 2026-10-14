#include<bits/stdc++.h>
using ll = long long;
using vll = std::vector<ll>;
using namespace std;

// === 素因数分解 ===
// 計算量: O(√N)
// 返り値: {素数, 指数} の map
map<ll, ll> prime_factor(ll n) {
    map<ll, ll> ret;
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ret[i]++;
            n /= i;
        }
    }
    if (n != 1) ret[n] = 1;
    return ret;
}

/*
--- main関数内での書き方例 ---
auto factors = prime_factor(360); // {2:3, 3:2, 5:1}
for (auto [prime, count] : factors) {
    // 処理
}
*/