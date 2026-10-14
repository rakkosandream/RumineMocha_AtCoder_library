/*
vectorの二分探索
vll v = {1, 2, 5, 9, 20, 100};
ll key = 5;

// lower_bound (v[i] >= key と初めてなるようなイテレータを返す)
auto it_lower = lower_bound(all(v), key);
if (it_lower != v.end()) {
    cout << *it_lower << endl; // 値の表示(5)
} else {
    cout << "key以上の要素は存在しません" << endl; 
} 
cout << it_lower - v.begin() << endl; // 先頭からの距離を表示(2, 0-origin)
cout << v.end() - it_lower << endl; // 末尾までの距離を表示(4)

it_lower - v.begin() でvの要素でkey未満の値の個数が分かる。
v.end() - it_lower   でvの要素でkey以上の値の個数が分かる。

// upper_bound (v[i] > key と初めてなるようなイテレータを返す)
auto it_upper = upper_bound(all(v), key);
if (it_upper != v.end()) {
    cout << *it_upper << endl; // 値の表示(9)
} else {
    cout << "key以上の要素は存在しません" << endl; 
}  
cout << it_upper - v.begin() << endl; // 先頭からの距離を表示(3, 0-origin)
cout << v.end() - it_upper << endl; // 末尾までの距離を表示(3)

it_upper - v.begin() でvの要素でkey以下の値の個数が分かる。
v.end() - it_upper   でvの要素でkeyを超えるの値の個数が分かる。

it_upper - it_lower でkeyの値の要素の個数を求めることが可能。

lower_bound(v.begin() + num_1, v.begin() + num_2, key)
で範囲指定可能。上記のit_lower - v.begin()等と組み合わせて数字指定も可能。
// 第一要素は昇順(小さい順), 第二要素は降順(大きい順)に並べる方法
auto comp = [](const pll &a, const pll &b){
    if(a.first != b.first){
        return a.first < b.first;
    }else{
        return a.second > b.second;
    }
};
sort(ALL(A), comp);
のようにソートを行うことができる。
*/