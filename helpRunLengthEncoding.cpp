#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
#define rep(i, n) for(ll i=0;i<(n);i++)

// === ランレングス圧縮 (Run-Length Encoding) ===
// 計算量: O(N) / 連続する同じ要素を {要素, 個数} のペアに圧縮する
// 例: "AABBBC" -> {{'A', 2}, {'B', 3}, {'C', 1}}
template <typename T>
auto rle(const T& s) {
    using Element = typename T::value_type;
    vector<pair<Element, int>> res;
    int n = s.size();
    for (int i = 0; i < n;) {
        int j = i + 1;
        while (j < n && s[i] == s[j]) j++;
        res.push_back({s[i], j - i});
        i = j;
    }
    return res;
}

/*
--- main関数内での書き方例 ---
string S = "AABBBC";
auto encoded_str = rle(S); // vector<pair<char, int>> が返る
for (auto [ch, count] : encoded_str) {
    cout << ch << ": " << count << endl;
}

// vectorのランレングス圧縮も可能
vll A = {1, 1, 2, 2, 2, 1};
auto encoded_vec = rle(A); // vector<pair<ll, int>> が返る
*/