// === ワーシャルフロイド法 ===
// 計算量: O(N^3) / 全点対間最短経路を求める
// dist[i][j] : iからjへの最短距離。初期値はINF (ただし dist[i][i] = 0)
/*
void warshall_floyd(vvll& dist) {
    ll n = dist.size();
    rep(k, n) {
        rep(i, n) {
            rep(j, n) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    CHMIN(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}
*/

/*
--- main関数内での書き方例 ---
vvll dist(N, vll(N, INF));
rep(i, N) dist[i][i] = 0;
rep(i, M) {
    ll u, v, c;
    CIN(u, v, c); // 0-indexed
    dist[u][v] = c; // 有向グラフの場合
    // dist[v][u] = c; // 無向グラフならこちらも
}
warshall_floyd(dist);
*/