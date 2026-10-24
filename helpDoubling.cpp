#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
#define rep(i, n) for(ll i=0;i<(n);i++)

/*
VEC(ll, A, N);
vvll doubling;
doubling.push_back(A);  // 1回目の操作
ll maxNum = 1e9;
rep3(i, 1, INF){
    doubling.push_back(A);
    rep(j, N){
        doubling[i][j] = doubling[i-1][doubling[i-1][j]];   // 2^i回目の操作
    }

    if(maxNum < (1LL << i)){
        break;
    }
}

rep3(i, 1, MAX_REPEAT){
    rep(j, N){
        rep(k, N){
            rep(l, N){
                // doubling[対象の層][始点][終点]
                // doubling[i][j][k]の値を更新したい
                // doubling[i-1][j][l] i-1層で始点はjで、終点はl
                // doubling[i-1][l][k] i-1層で始点はlで、終点はk => lを経由する際のコストを表現
                CHMIN(doubling[i][j][k], doubling[i-1][j][l] + doubling[i-1][l][k]);
            }
        }
    }
}

// 提出例：https://atcoder.jp/contests/abc445/submissions/80288660
*/