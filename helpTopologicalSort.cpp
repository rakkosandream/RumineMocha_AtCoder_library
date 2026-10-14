#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
#define rep(i, n) for(ll i=0;i<(n);i++)

// === トポロジカルソート (Kahn's Algorithm) ===
// 計算量: O(V + E) / 有向グラフの頂点を依存関係順に並び替える
// G: グラフ, N: 頂点数
// 返り値: ソートされた頂点リスト (閉路がある場合は空のvectorを返す)
vll topological_sort(const vector<vll> &G, ll N) {
    vll res;
    vll indegree(N, 0); // 入次数
    rep(i, N) for (ll next : G[i]) indegree[next]++;
    
    queue<ll> q; // 入次数が0のものをキューに追加
    rep(i, N) if (indegree[i] == 0) q.push(i);
    
    while (!q.empty()) {
        ll v = q.front(); q.pop();
        res.push_back(v);
        for (ll next : G[v]) {
            indegree[next]--;
            if (indegree[next] == 0) q.push(next);
        }
    }
    
    if (res.size() != (size_t)N) return {}; // 閉路がある場合
    return res;
}

/*
--- main関数内での書き方例 ---
ll N, M; cin >> N >> M;
vector<vll> G(N);
rep(i, M) {
    ll u, v; cin >> u >> v;
    u--; v--; // 0-indexed
    G[u].push_back(v); // 有向グラフ
}

vll sorted_order = topological_sort(G, N);
if (sorted_order.empty()) {
    // 閉路(サイクル)が存在し、トポロジカルソート不可能な場合
} else {
    for (ll v : sorted_order) cout << v + 1 << " ";
}
*/