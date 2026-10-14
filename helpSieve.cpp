#include<bits/stdc++.h>
using ll = long long;
using vll = std::vector<ll>;
using namespace std;

// === エラトステネスの篩（線形篩） ===
// 計算量: 構築 O(N), 素数判定 O(1), 素因数分解 O(log N)
struct Sieve {
    vll min_prime; // 最小素因数 (Smallest Prime Factor)
    vll primes;    // 素数リスト

    // 入力は素数判定したい数の上限(10だったら2, 3, 5, 7が生成される)
    Sieve(ll n) : min_prime(n + 1, -1) {
        for (ll i = 2; i <= n; i++) {
            if (min_prime[i] == -1) {
                min_prime[i] = i;
                primes.push_back(i);
            }
            for (ll p : primes) {
                if (p > min_prime[i] || i * p > n) break;
                min_prime[i * p] = p;
            }
        }
    }

    // 素数判定
    bool is_prime(ll n) {
        if (n < 2) return false;
        return min_prime[n] == n;
    }

    // 高速素因数分解
    map<ll, ll> factorize(ll n) {
        map<ll, ll> res;
        while (n > 1) {
            res[min_prime[n]]++;
            n /= min_prime[n];
        }
        return res;
    }
};

/*
--- main関数内での書き方例 ---
Sieve sieve(1000000); 
if (sieve.is_prime(97)) {
    // 素数のときの処理
}
auto factors = sieve.factorize(120); // {2:3, 3:1, 5:1}
*/