/*
bit全探索
rep(bit, 1<<N){ // 2のN乗を表す
    ll A=0, B=0;
    rep(i, N){
        if(bit>>i & 1) A += K[i]; // 各ビットが0 or 1かを判定
        else B += K[i];
    }
}
*/