/*
bitDPの実装例：https://atcoder.jp/contests/abc180/submissions/79076819
巡回セールスマン問題などのO(N!)の計算量をO(2^N * N^2)に落とすことができる。
大体N <= 18 程度までなら間に合う。
集合に対する計算を高速に行うことができる。
ex. 巡回セールスマン問題 
=> N個の都市が存在するときの全ての都市を回って帰ってくるときに必要な総コストの最小値を求める問題。
=> 回った都市の集合(2^N個)を考え、最後に訪れた都市を変数(N個)として保持する
// 入力
LL(N);
vtll locate;
rep(i, N){
    LL(X, Y, Z);
    locate.emplace_back(X, Y, Z);
}

// 遷移コスト算出
// from -> 遷移元, to -> 遷移先
auto trans_cost = [&](ll from, ll to) ->ll{
    auto [a, b, c] = locate[from];
    auto [p, q, r] = locate[to];

    ll result = abs(p-a) + abs(q-b) + max(0LL, r-c);
    return result;
};

// 要素集合の総数(2^N)
ll repeat = (1LL<<N);

// 要素集合に対する最終位置を持つ
vvll dp(repeat, vll(N, INF));

// 最初の点のコストは0
dp[1][0] = 0;

// 全ての集合を探索する
rep3(i, 1, repeat){

    // その集合の終了位置を全探索
    rep(j, N){

        // その集合に含まれていない場合はcontinue
        if(dp[i][j] == INF){
            continue;
        }

        // 考えられる遷移先についてコストを計算する(配るDP)
        rep(k, N){

            // 既に遷移している場合はcontinue
            if((i >> k) & 1LL){
                continue;
            }

            // 遷移していない場合はコストの更新処理
            // next => 集合i に要素k を加えた集合
            ll next = i | (1LL << k);

            // 集合next で、最後の遷移先がk の時のコストは、
            // 現在のコスト、集合iの終了位置がj番目から、集合nextの遷移先がkになるためのコストの和 の最小値
            CHMIN(dp[next][k], dp[i][j] + trans_cost(j, k));
        }
    }
}

// 巡回セールスマン問題の場合は最後に自分に返ってくる必要がある
// lastは全ての要素を持つ集合を表す
ll last = repeat - 1;
ll ans = INF;

// 集合lastから要素0に変えるまでのコストを計算する。
// 終了位置は何でもOK。
rep(i, N){
    if(dp[last][i] != INF){
        CHMIN(ans, dp[last][i] + trans_cost(i, 0));
    }
}

pr(ans);

return 0
*/