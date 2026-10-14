/*
=== 転倒数 (スワップ回数) の計算 ===
計算量はO(N log N)で、座標圧縮 + BITを用いて実装。

ll get_inversions(const vector<ll>& A) {
    int n = A.size();
    // 座標圧縮
    vector<ll> vals = A;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    
    fenwick_tree<ll> bit(vals.size());
    ll inversions = 0;
    for (int i = 0; i < n; ++i) {
        int rank = lower_bound(vals.begin(), vals.end(), A[i]) - vals.begin();
        inversions += i - bit.sum(0, rank + 1);
        bit.add(rank, 1);
    }
    return inversions;
}

--- 具体例 ---
// vector<ll> A = {5, 3, 2, 4, 1};
// ll inv = get_inversions(A);
// cout << inv << endl; // 出力: 8
*/