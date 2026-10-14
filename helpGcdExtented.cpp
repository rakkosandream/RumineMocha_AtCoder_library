#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
#define rep(i, n) for(ll i=0;i<(n);i++)

// === 拡張ユークリッドの互除法 ===
// 計算量: O(log(min(a, b)))
// ax + by = gcd(a, b) を満たす整数解 (x, y) を求め、gcd(a, b) を返す
ll extgcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    ll d = extgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

// 応用: 任意Mod下での逆元（a と mod が互いに素である必要あり）
ll modinv_general(ll a, ll mod) {
    ll x, y;
    extgcd(a, mod, x, y);
    return (x % mod + mod) % mod;
}

/*
--- main関数内での書き方例 ---
ll x, y;
extgcd(111, 30, x, y); // 111x + 30y = 3 となる (x, y) = (3, -11) などが求まる

// 素数ではないかもしれない MOD 下での「 1 / 5 」の値を求める
ll inv_five = modinv_general(5, 1000000);
*/