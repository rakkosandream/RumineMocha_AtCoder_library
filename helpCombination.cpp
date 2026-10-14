#include<bits/stdc++.h>
using ll = long long;
using vll = std::vector<ll>;
using vvll = std::vector<vll>;
using namespace std;

// ====================================================================
// 組み合わせ計算 (nCr) 詰め合わせスニペット
// ====================================================================
// 【使い分けの目安】
// 1. conbi(n, r)          : Modなし / N <= 60 程度 / 単発計算 [O(r)]
// 2. init_combination_dp  : Mod任意 / N <= 5000 程度 / 多クエリ [前処理 O(N^2) / クエリ O(1)]
// 3. CombinationMod       : Mod素数 / N <= 10^7 程度 / 多クエリ [前処理 O(N) / クエリ O(1)] ※最頻出
// 4. nCr_large_n          : Mod素数 / N <= 10^9 巨大, r <= 10^6 [クエリ O(r log MOD)]
// ====================================================================

// 1. Modなし・単発計算: O(r)
ll conbi(ll n, ll r) {
    if (r < 0 || r > n) return 0;
    if (r > n / 2) r = n - r;
    ll res = 1;
    for (ll i = 1; i <= r; ++i) res = res * (n - i + 1) / i;
    return res;
}

// 2. パスカルの三角形（Mod任意・Nが小さい場合の多クエリ）: 前処理 O(N^2) / クエリ O(1)
vvll com;
void init_combination_dp(ll n, ll mod = 0) {
    com.assign(n + 1, vll(n + 1, 0));
    for (ll i = 0; i <= n; i++) {
        com[i][0] = 1;
        for (ll j = 1; j <= i; j++) {
            if (mod > 0) com[i][j] = (com[i - 1][j - 1] + com[i - 1][j]) % mod;
            else com[i][j] = com[i - 1][j - 1] + com[i - 1][j];
        }
    }
}

// 3. 階乗逆元テーブル（Mod素数・標準的な多クエリ）: 前処理 O(N) / クエリ O(1)
struct CombinationMod {
    vll fact, inv, fact_inv;
    ll mod;
    CombinationMod(ll n, ll m) : fact(n + 1), inv(n + 1), fact_inv(n + 1), mod(m) {
        fact[0] = fact[1] = 1; fact_inv[0] = fact_inv[1] = 1; inv[1] = 1;
        for (ll i = 2; i <= n; i++) {
            fact[i] = fact[i - 1] * i % mod;
            inv[i] = mod - inv[mod % i] * (mod / i) % mod;
            fact_inv[i] = fact_inv[i - 1] * inv[i] % mod;
        }
    }
    ll nCr(ll n, ll r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * fact_inv[r] % mod * fact_inv[n - r] % mod;
    }
};

// 4. Nが巨大かつrが小さい場合（Mod素数・単発計算）: O(r log MOD)
ll extgcd_nCr(ll a, ll b, ll& x, ll& y) {
    if (b == 0) { x = 1; y = 0; return a; }
    ll d = extgcd_nCr(b, a % b, y, x);
    y -= a / b * x; return d;
}
ll modinv_nCr(ll a, ll m) { ll x, y; extgcd_nCr(a, m, x, y); return (x % m + m) % m; }
ll nCr_large_n(ll n, ll r, ll mod) {
    if (r < 0 || r > n) return 0;
    if (r > n / 2) r = n - r;
    ll num = 1, den = 1;
    for (ll i = 0; i < r; i++) {
        num = num * ((n - i) % mod) % mod;
        den = den * ((i + 1) % mod) % mod;
    }
    return num * modinv_nCr(den, mod) % mod;
}

/*
--- main関数内での書き方例 ---
const ll MOD = 998244353;

// 1. Modなし・単発
ll ans1 = conbi(10, 3); // 120

// 2. パスカルの三角形 (例: N <= 3000, 任意のMod)
init_combination_dp(3000, MOD);
ll ans2 = com[100][50];

// 3. 階乗逆元テーブル (例: N <= 200000, 素数Mod) ※基本はこれ
CombinationMod cm(200000, MOD);
ll ans3 = cm.nCr(100, 50);

// 4. Nが巨大、rが小さい (例: N = 10^9, r = 100000, 素数Mod)
ll ans4 = nCr_large_n(1000000000, 100000, MOD);
*/