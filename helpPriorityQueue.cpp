/*
優先度付きキュー(priority_queue)の使い方
priority_queue<ll> pq; // デフォルトは降順 (最大値が先頭)

// 基本操作
pq.push(x);  // 要素の挿入 (O(logN))
ll val = pq.top(); // 最大値(先頭)の取得 (O(1))
pq.pop();    // 最大値(先頭)の削除 (O(logN))
pq.empty();  // 空かどうかの判定
pq.size();   // 要素数の取得

// 昇順 (最小値が先頭) にする場合
priority_queue<ll, vector<ll>, greater<ll>> pq_asc;

// --- 自分で比較関数(順序)を定義する場合 ---
// ※注意: priority_queueの比較関数は sort() と逆！
// true を返した方が「優先度が低い（後回しになる）」という仕様。
// 考え方：「aを後回しにすべき条件」を書く。

// 例: pairの第二要素は昇順(小さい順)、同じなら第一要素は降順(大きい順)にしたい場合
auto comp = [](const pll &a, const pll &b){
    if(a.second != b.second){
        // 第二要素は昇順にしたい → a の方が大きい時に「後回し(true)」にする
        return a.second > b.second; 
    }else{
        // 第一要素は降順にしたい → a の方が小さい時に「後回し(true)」にする
        return a.first < b.first; 
    }
};
priority_queue<pll, vector<pll>, decltype(comp)> custom_pq(comp);
*/