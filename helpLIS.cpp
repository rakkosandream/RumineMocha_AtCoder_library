/*
=== 最長増加部分列 (LIS) の計算 ===
※ 計算量: O(N log N)

ll get_lis(const vector<ll>& A) {
    vector<ll> dp;
    for (ll a : A) {
        // 狭義単調増加 (a < b < c ...) を求める場合は lower_bound
        // 広義単調増加 (a <= b <= c ...) を求める場合は upper_bound
        auto it = lower_bound(dp.begin(), dp.end(), a);
        if (it == dp.end()) {
            dp.push_back(a);
        } else {
            *it = a;
        }
    }
    return dp.size();
}

--- 具体例 ---
// vector<ll> A = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
// ll lis_len = get_lis(A);
// cout << lis_len << endl; // 出力: 4 (例: 1, 2, 5, 9 など)
*/