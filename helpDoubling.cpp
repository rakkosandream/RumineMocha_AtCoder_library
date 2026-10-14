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
*/