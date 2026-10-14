#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
#define rep(i, n) for(ll i=0;i<(n);i++)

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

// [l, r] の整数一様乱数
ll rnd(ll l, ll r) {
    return uniform_int_distribution<ll>(l, r)(rng);
}

// [l, r) の実数一様乱数
double rnd_real(double l, double r) {
    return uniform_real_distribution<double>(l, r)(rng);
}

// 1 から n のランダム順列
vector<ll> rnd_perm(ll n) {
    vector<ll> p(n);
    iota(p.begin(), p.end(), 1);
    shuffle(p.begin(), p.end(), rng);
    return p;
}

// [l, r] から k 個の重複しない値を選ぶ (巨大な範囲に対応)
vector<ll> rnd_unique(ll l, ll r, ll k) {
    set<ll> st;
    while ((ll)st.size() < k) {
        st.insert(rnd(l, r));
    }
    vector<ll> res(st.begin(), st.end());
    shuffle(res.begin(), res.end(), rng); // 順序もランダムにする
    return res;
}