#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;

// === 座標圧縮 (Coordinate Compression) ===
// 計算量: 構築 O(N log N) / クエリ O(log N)
// 元の値を座圧後の値(0-indexed)に変換する
template <typename T>
struct Compressor {
    vector<T> vals;

    // コンストラクタ: 構築時に座圧まで済ませる
    Compressor(vector<T> v) : vals(v) {
        sort(all(vals));
        vals.erase(unique(all(vals)), vals.end());
    }

    // 値 x が何番目か(0-indexed)を返す
    int get(T x) const {
        return lower_bound(all(vals), x) - vals.begin();
    }

    // 座圧後の i 番目の元の値を返す（逆変換）
    T operator[](int i) const {
        return vals[i];
    }

    // 座圧後の要素数を返す
    int size() const {
        return vals.size();
    }
};

/*
--- main関数内での書き方例 ---
vll A = {100, 2, 100, 50, 2};
Compressor<ll> cp(A); // ここで座圧完了

rep(i, A.size()) {
    cout << cp.get(A[i]) << " "; // get(値) でインデックス取得
}
// 出力: 2 0 2 1 0

cout << cp[0] << endl; // cp[インデックス] で元の値 (2) を取得
cout << cp.size() << endl; // ユニークな要素数 (3)
*/