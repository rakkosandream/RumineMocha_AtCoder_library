// === ダイクストラ法 ===
// 計算量: O(M log N) / 単一始点最短経路を求める（負のコストがない場合）
// graph: 隣接リスト。graph[u] = { {v, cost}, ... }
// start: 始点
// dist: 距離を格納する配列 (参照渡しで更新)
/*
void dijkstra(const vector<vector<pll>>& graph, ll start, vll& dist) {
    dist.assign(graph.size(), INF);
    dist[start] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, start}); // {cost, v}

    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();

        if (d > dist[v]) continue;

        for (auto& edge : graph[v]) {
            ll to = edge.first;
            ll cost = edge.second;
            if (CHMIN(dist[to], dist[v] + cost)) {
                pq.push({dist[to], to});
            }
        }
    }
}
*/

/*
--- main関数内での書き方例 ---
ll N, M; cin >> N >> M;
vector<vector<pll>> G(N);
rep(i, M) {
    ll u, v, w; cin >> u >> v >> w;
    u--; v--; // 0-indexed
    G[u].push_back({v, w});
    G[v].push_back({u, w}); // 無向グラフの場合
}
vll dist;
dijkstra(G, 0, dist);
*/