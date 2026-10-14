/*
集合(set)の使い方
setll st;
st.insert(num)  // 挿入法
st.count(num)  // 検索法一つ目
st.contains(num)  // 検索法二つ目
ll min_val = *st.begin(); 最小値の取得方法
ll max_val = *st.rbegin(); // 最大値の取得方法
ll target = *st.lower_bound(num); // 二分探索(num以上の最小の要素) (※endチェック必須！)
ll target = *st.upper_bound(num); // 二分探索(numを超えるの最小の要素)

// 二分探索 (※endチェック必須！)
auto it = st.lower_bound(num); // num以上のイテレータ
if (it != st.end()) {
    ll val = *it; // ここで初めて値を取り出す
} else {
    // num以上の値は存在しない場合の処理
}

st.erase(num)  // 要素の削除法

while(!st.empty()){ // 破壊的操作をする場合
    auto temp = A.front();
    cout << temp.first << " " << temp.second << endl  // 全要素の表示
    st.pop();
}

for(auto temp : st){ // 破壊的操作をしない場合
    cout << temp.first << " " << temp.second << endl  // 全要素の表示
}
A.size()  // 濃度の表示

二分探索 or 最大値 or 最小値 => set, multiset
自分でハッシュ関数を定義する場合 => unordered_set (平均O(1), 最悪O(N))

比較関数を自分で定義する場合

// 第一要素は昇順(小さい順), 第二要素は降順(大きい順)に並べる方法
auto comp = [](const pll &a, const pll &b){
    if(a.first != b.first){
        return a.first < b.first;
    }else{
        return a.second > b.second;
    }
};
set<pll, decltype(comp)> nums(comp);
*/