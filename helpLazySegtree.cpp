/*
lazy_segmentree(遅延セグ木)

(1)区間和取得 ^ 区間加算(区間を指定し、その範囲全てに数字を加える操作)
// ノードの型（区間の和 と 区間の長さ を保持）
struct S {
    long long value;
    int size;
};

// 遅延評価の型（加算する値）
using F = long long;

// 二つのノードをマージする関数（和と長さをそれぞれ足す）
S op(S a, S b) { return {a.value + b.value, a.size + b.size}; }

// 単位元（和0、長さ0）
S e() { return {0, 0}; }

// 遅延評価をノードに適用する関数（区間加算）
// 区間の和は (加算する値 * 区間の長さ) だけ増える
S mapping(F f, S x) { return {x.value + f * x.size, x.size}; }

// 遅延タグを合成する関数（後から来た f を既存の g に足す）
F composition(F f, F g) { return f + g; }

// 遅延タグの単位元（加算において影響を与えない値）
F id() { return 0; }

// 使用例
void example_sum() {
    int n = 5;
    // 初期配列の構築（各要素は 値0、長さ1）
    vector<S> init_data(n, {0, 1}); 
    
    // セグメント木の宣言
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(init_data);

    seg.apply(1, 4, 3); // 区間 [1, 4) に 3 を加算
    cout << seg.prod(0, 5).value << endl; // 区間 [0, 5) の総和を取得
}

(2)区間最小値取得 ^ 区間更新(指定した区間を指定した値に更新)
// ノードの型（区間の最小値）と遅延評価の型（更新する値）
using S = long long;
using F = long long;

const S INF = 1e18; // 区間最小値の単位元
const F ID = 1e18;  // 遅延評価の単位元（絶対に更新値として使われない値）

// 二つのノードをマージする関数（区間最小値）
S op(S a, S b) { return std::min(a, b); }

// 単位元（最小値の計算に影響を与えない値）
S e() { return INF; }

// 遅延評価をノードに適用する関数（区間更新）
// 遅延タグ f が単位元 ID でなければ、区間の最小値は f に上書きされる
S mapping(F f, S x) { return (f == ID) ? x : f; }

// 遅延タグを合成する関数（後から来た f で既存の g を上書きする）
// 後から来た操作 f が優先されるため、f が ID でなければ f を返す
F composition(F f, F g) { return (f == ID) ? g : f; }

// 遅延タグの単位元（更新を行わないことを示す値）
F id() { return ID; }

// 使用例
void example_min_update() {
    int n = 5;
    vector<S> A(n, 0); // 初期配列（例: 全て0）
    
    // セグメント木の宣言
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(A);

    seg.apply(1, 4, 5); // 区間 [1, 4) の値を 5 に更新（上書き）
    cout << seg.prod(0, 5) << endl; // 区間 [0, 5) の最小値を取得
}

(3)区間最小値取得 ^ 区間加算(区間を指定し、その範囲全てに数字を加える操作)
// ① データの型（区間の最小値）
using S = long long;

// ② 操作の型（加算する値）
using F = long long;

const S INF = 1e18; // 区間最小値の単位元

// ③ データをマージする関数（区間最小値）
S op(S a, S b) { return std::min(a, b); }

// ④ データの単位元（最小値の計算に影響を与えない値）
S e() { return INF; }

// ⑤ データ S に操作 F を反映させる関数（区間加算）
// 区間内の全ての要素に f が足されるため、その区間の最小値もそのまま f 増える
S mapping(F f, S x) { return f + x; }

// ⑥ 操作 F と操作 F を合成する関数（後から来た f を既存の g に足す）
// 例: すでに 5 を足す予約(g)がある所に、新たに 3 を足す(f)と、合計 8 を足すことになる
F composition(F f, F g) { return f + g; }

// ⑦ 操作の単位元（加算において影響を与えない値）
F id() { return 0; }

// 使用例
void example_min_add() {
    int n = 5;
    vector<S> A(n, 0); // 初期配列（例: 全て0）
    
    // セグメント木の宣言
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(A);

    seg.apply(1, 4, 10); // 区間 [1, 4) の全ての要素に 10 を加算
    cout << seg.prod(0, 5) << endl; // 区間 [0, 5) の最小値を取得
}
*/