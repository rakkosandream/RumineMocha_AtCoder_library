/*
=== ラムダ式 (&あり: 参照キャプチャ) ===
※ 外部の変数（vectorなど）をコピーせずに直接参照・更新できます。
※ グラフの探索(DFS)など、関数内で外部配列を触る再帰関数を書く際に非常に便利です。

// --- 再帰関数 (DFS) の具体例 ---
// auto dfs = [&](auto self, int v, int p) -> void {
//     for (int u : G[v]) {
//         if (u == p) continue;
//         // 行いたい処理
//         self(self, u, v);
//     }
// };
// 
// 呼び出し: dfs(dfs, 0, -1);
*/
/*
=== ラムダ式 (&なし: キャプチャなし / コピーキャプチャ) ===
※ 外部変数を変更しない、または純粋な比較関数を定義する場合に使用します。
※ std::sort や std::lower_bound のカスタム比較関数としてよく使われます。

// --- カスタムソートの具体例 (キャプチャなし []) ---
// auto cmp = [](const pair<ll, ll>& a, const pair<ll, ll>& b) -> bool {
//     if (a.first != b.first) {
//         return a.first < b.first; // 1番目の要素は昇順
//     }
//     return a.second > b.second;   // 2番目の要素は降順
// };
// 
// vector<pair<ll, ll>> A = {{1, 2}, {1, 5}, {2, 3}};
// sort(A.begin(), A.end(), cmp);
*/