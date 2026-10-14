#include<bits/stdc++.h>
using ll = long long;
using namespace std;

// === 最大公約数 (GCD) / 最小公倍数 (LCM) ===
// 計算量: O(log(min(a, b)))
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; } // オーバーフロー注意