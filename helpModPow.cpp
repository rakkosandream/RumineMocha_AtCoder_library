#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
#define rep(i, n) for(ll i=0;i<(n);i++)

// === 繰り返し二乗法 (高速べき乗計算) ===
// 計算量: O(log N) / (a^n) % mod を高速に求める
ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    a %= mod;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

/*
--- main関数内での書き方例 ---
const ll MOD = 998244353;
// 2^100000 % MOD を求める
ll ans = modpow(2, 100000, MOD);
*/