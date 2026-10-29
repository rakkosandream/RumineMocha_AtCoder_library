#include<bits/stdc++.h>
using ll = long long;
using vll = std::vector<ll>;
using vbo = std::vector<bool>;
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

// 区間 [L, R] に含まれる素数のリストを昇順で返す
// 制約目安: R <= 10^14, R - L <= 10^7
vll segmented_sieve(ll L, ll R) {
    if (L > R || R < 2) return {};

    ll sqrt_R = sqrt(R);
    vbo is_small_prime(sqrt_R + 1, true);
    is_small_prime[0] = is_small_prime[1] = false;

    // 1. sqrt(R) 以下の素数を通常の篩で列挙
    vll small_primes;
    for (ll p = 2; p <= sqrt_R; ++p) {
        if (is_small_prime[p]) {
            small_primes.push_back(p);
            for (ll q = p * p; q <= sqrt_R; q += p) {
                is_small_prime[q] = false;
            }
        }
    }

    // 2. 区間 [L, R] の合成数を篩い落とす
    vbo is_prime(R - L + 1, true);

    for (ll p : small_primes) {
        ll start = max(p * p, (L + p - 1) / p * p);
        for (ll q = start; q <= R; q += p) {
            is_prime[q - L] = false;
        }
    }

    // 3. 1 以下の例外処理
    if (L <= 1) {
        for (ll x = L; x <= min(R, 1LL); ++x) {
            is_prime[x - L] = false;
        }
    }

    // 4. 素数のみを配列に格納
    vll primes;
    for (ll x = L; x <= R; ++x) {
        if (is_prime[x - L]) {
            primes.push_back(x);
        }
    }

    return primes;
}

/*
--- main関数内での書き方例 ---
Sieve sieve(1000000); 
if (sieve.is_prime(97)) {
    // 素数のときの処理
}
auto factors = sieve.factorize(120); // {2:3, 3:1, 5:1}

int main() {
    // 例: 10^14 周辺の区間 [10^14, 10^14 + 100] の素数列挙
    ll L = 100000000000000LL;
    ll R = L + 100;
    vll primes = segmented_sieve(L, R);

    for (ll p : primes) {
        cout << p << " ";
    }
    cout << "\n";
    // 出力: 100000000000031 100000000000067 100000000000097 100000000000099
}
*/