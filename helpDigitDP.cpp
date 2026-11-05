/*
STR(N);
vector<vvvmi> dp(N.size(), vvvmi(2, vvmi(3, vmi((1LL << 10), 0))));

ll num = N[0] - '0';
rep3(i, 1, num) {
    // 0 がないのはLeading zero対策
    dp[0][true][i % 3][(1LL << i)] += 1;
}
dp[0][false][num % 3][(1LL << num)] = 1;

rep3(i, 1, N.size()) {
    num = N[i] - '0';

    // Leading zero対策
    rep3(l, 1, 10) {
        dp[i][true][l % 3][1 << l] += 1;
    }

    // true -> true
    rep(j, 3) {
        rep(k, (1LL << 10)) {
            rep(l, 10) {
                dp[i][true][(j + l) % 3][k | (1LL << l)] += dp[i - 1][true][j][k];
            }
        }
    }

    // false -> true
    rep(j, 3) {
        rep(k, (1LL << 10)) {
            rep(l, num) {
                dp[i][true][(j + l) % 3][k | (1LL << l)] += dp[i - 1][false][j][k];
            }
        }
    }

    // false -> false
    rep(j, 3) {
        rep(k, (1LL << 10)) {
            dp[i][false][(j + num) % 3][k | (1LL << num)] += dp[i - 1][false][j][k];
        }
    }
}
*/
