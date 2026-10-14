#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;

// === プリム法 (Prim's Algorithm) ===
// 計算量: O(M log N) / 最小全域木 (MST) の総コストを求める
// graph: 隣接リスト。graph[u] = { {v, cost}, ... }
// 返り値: 最小全域木の総コスト (頂点0を含む連結成分のMST)
ll prim(const vector<vector<pll>>& graph) {
    ll N = graph.size();
    ll sum = 0;
    vector<bool> visited(N, false);
    
    // {cost, v} のペア。コストが小さい順に取り出す
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    
    // 頂点0からスタート (コスト0)
    pq.push({0, 0}); 

    while (!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();

        // 既に木に含まれているならスキップ
        if (visited[u]) continue;

        // 木に含める
        visited[u] = true;
        sum += cost;

        // 隣接する頂点を候補に追加
        for (auto& edge : graph[u]) {
            ll v = edge.first;
            ll w = edge.second;
            if (!visited[v]) {
                pq.push({w, v});
            }
        }
    }
    return sum;
}

/*
--- main関数内での書き方例 ---
ll N, M; cin >> N >> M;
vector<vector<pll>> G(N);
rep(i, M) {
    ll u, v, w; cin >> u >> v >> w;
    u--; v--; // 0-indexed
    G[u].push_back({v, w});
    G[v].push_back({u, w}); // 無向グラフ
}
cout << prim(G) << endl;
*/