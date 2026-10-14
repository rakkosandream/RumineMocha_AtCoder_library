/*
=== セグメント木 (区間最大値) ===
ll op_max(ll a, ll b) { return max(a, b); } // 二項演算
ll e_max() { return -INF; }                 // 単位元

// 初期化 (サイズ N または vector A)
// segtree<ll, op_max, e_max> t_max(N);
// segtree<ll, op_max, e_max> t_max(A);

--- 具体例 (区間最大値) ---
// t_max.set(2, 10);          // 0-indexed で 2 番目の要素を 10 に更新
// ll val = t_max.get(2);     // 2 番目の要素を取得
// ll res = t_max.prod(1, 4); // 半開区間 [1, 4) の最大値を取得

// セグ木上の二分探索 (例: 左端 0 から見て、最大値が target 未満となる最大の右端)
// ll target = 10;
// auto f = [&](ll v) { return v < target; };
// int idx = t_max.max_right(0, f); 

=== セグメント木 (区間和) ===
ll op_sum(ll a, ll b) { return a + b; } // 二項演算
ll e_sum() { return 0; }                // 単位元

// 初期化 (サイズ N または vector A)
// segtree<ll, op_sum, e_sum> t_sum(N);
// segtree<ll, op_sum, e_sum> t_sum(A);

--- 具体例 (区間和) ---
// t_sum.set(2, t_sum.get(2) + 5); // 2 番目の要素に 5 を加算 (直接足すメソッドはないため)
// ll sum = t_sum.prod(1, 4);      // 半開区間 [1, 4) の合計を取得
*/