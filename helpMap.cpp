/*
辞書(map)の使い方
mapll dict; //定義
dict.insert{(key, value})  // 挿入法一つ目
dist[key] = value  // 挿入法二つ目
dict.erase(key)  // 要素の削除法
Yes(dict.count(key))  // 検索法一つ目
Yes(dict.contains(key))  // 検索法二つ目
ll min_val = *dict.begin(); 最小値の取得方法
ll max_val = *dict.rbegin(); // 最大値の取得方法
for(auto temp : dict){
    cout << temp.first << " " << temp.second << endl  // 全要素の表示
}

dict.count(key) > 0 // keyに対応するvalueの存在チェック
*/