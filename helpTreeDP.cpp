#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
#define rep(i, n) for(ll i=0;i<(n);i++)

// === 全方位木DP (Re-rooting Tree DP) ===
// 計算量: O(N) / 任意の頂点を根としたときの木DPの値を全頂点について求める
// 概要: 左右からの累積和を用いて、部分木の結果を高速にマージ・伝播させる
template <class T, class Merge, class E, class PutEdge>
struct ReRooting {
    ll n;
    vector<vector<ll>> g;
    Merge merge;
    E e;
    PutEdge put_edge;
    vector<vector<T>> dp; // dp[v][i]: vからi番目の辺へ進む部分木の答え
    vector<T> ans;        // ans[v]: vを根としたときの全体の答え

    ReRooting(ll n, Merge merge, E e, PutEdge put_edge)
        : n(n), g(n), merge(merge), e(e), put_edge(put_edge), dp(n), ans(n) {}

    void add_edge(ll u, ll v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<T> build() {
        for (ll i = 0; i < n; i++) dp[i].resize(g[i].size());
        
        // dfs1: 葉から根へのボトムアップ計算 (仮の根を 0 とする)
        auto dfs1 = [&](auto self, ll v, ll p) -> T {
            T res = e();
            for (ll i = 0; i < (ll)g[v].size(); i++) {
                ll u = g[v][i];
                if (u == p) continue;
                dp[v][i] = self(self, u, v);
                res = merge(res, put_edge(dp[v][i], u));
            }
            return res;
        };
        dfs1(dfs1, 0, -1);

        // dfs2: 根から葉へのトップダウン計算 (親側の計算結果 pd を受け取る)
        auto dfs2 = [&](auto self, ll v, ll p, T pd) -> void {
            ll deg = g[v].size();
            for (ll i = 0; i < deg; i++) {
                if (g[v][i] == p) {
                    dp[v][i] = pd;
                    break;
                }
            }
            // 左右からの累積和
            vector<T> left(deg + 1, e()), right(deg + 1, e());
            for (ll i = 0; i < deg; i++) {
                left[i + 1] = merge(left[i], put_edge(dp[v][i], g[v][i]));
            }
            for (ll i = deg - 1; i >= 0; i--) {
                right[i] = merge(right[i + 1], put_edge(dp[v][i], g[v][i]));
            }
            
            ans[v] = left[deg];
            
            for (ll i = 0; i < deg; i++) {
                ll u = g[v][i];
                if (u == p) continue;
                T val = merge(left[i], right[i + 1]);
                self(self, u, v, val);
            }
        };
        dfs2(dfs2, 0, -1, e());
        return ans;
    }
};

/*
--- main関数内での書き方例 ---
// 例: 各頂点から最も遠い頂点までの距離を求める (木の最大距離)
ll N; cin >> N;

// 1. DPに乗せるデータの型 (今回は距離なので ll)
using Data = ll;

// 2. merge: 子の部分木同士を統合する関数
// 辺を統合する処理
auto merge = [](Data a, Data b) -> Data {
    return max(a, b);
};

// 3. e: 単位元 (初期値) を返す関数
auto e = []() -> Data {
    return 0;
};

// 4. put_edge: 部分木に辺を1本追加して親に渡すときの変化
// d: vのさらに奥を探索し終えた部分木のデータ, v: 今から辺を繋ごうとしている行き先の頂点
// 辺を作成する処理：今見ている頂点(親)から辺を伸ばしていき、伸ばす対象がvになるイメージ
// 任意の親から子(v)への辺を追加する際の処理を定義する関数
// この例だと、v以降の点の一番遠い点の距離がdで、そこに辺を1本追加するので距離が1増えるイメージ
auto put_edge = [](Data d, ll v) -> Data {
    return d + 1;
};

ReRooting<Data, decltype(merge), decltype(e), decltype(put_edge)> tree(N, merge, e, put_edge);

// 必ず 0-indexed で入力すること
for (ll i = 0; i < N - 1; i++) {
    ll u, v; cin >> u >> v;
    u--; v--; // 0-indexed
    tree.add_edge(u, v);
}

auto ans = tree.build(); // ans[i] に 頂点 i を根としたときの答えが入る
for (ll i = 0; i < N; i++) {
    cout << ans[i] << "\n";
}
// 活用例 : https://atcoder.jp/contests/abc428/submissions/77149961
*/