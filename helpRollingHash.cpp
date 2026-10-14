/*
========================================================================
【ローリングハッシュ（ダブルハッシュ）】
========================================================================
■ 使い方イメージ:
    std::string S = "abcdefg_abcde_xyz";
    RollingHash rh(S); // 構築: O(N)

    auto h1 = rh.get_hash(0, 5);  // 半開区間 [0, 5)  -> "abcde" のハッシュ
    auto h2 = rh.get_hash(8, 13); // 半開区間 [8, 13) -> "abcde" のハッシュ

    if (h1 == h2) std::cout << "Match!" << std::endl;
========================================================================
*/
/*
class RollingHash {
private:
    long long n;
    const long long base1 = 1007, mod1 = 1000000007;
    const long long base2 = 2009, mod2 = 1000000009;
    std::vector<long long> hash1, hash2;
    std::vector<long long> pow1, pow2;

public:
    RollingHash(const std::string &s) {
        n = s.length();
        hash1.assign(n + 1, 0);
        hash2.assign(n + 1, 0);
        pow1.assign(n + 1, 1);
        pow2.assign(n + 1, 1);
        for (long long i = 0; i < n; i++) {
            long long v = s[i];
            hash1[i + 1] = (hash1[i] * base1 + v) % mod1;
            hash2[i + 1] = (hash2[i] * base2 + v) % mod2;
            pow1[i + 1] = (pow1[i] * base1) % mod1;
            pow2[i + 1] = (pow2[i] * base2) % mod2;
        }
    }

    std::pair<long long, long long> get_hash(long long l, long long r) const {
        long long h1 = (hash1[r] - hash1[l] * pow1[r - l]) % mod1;
        if (h1 < 0) h1 += mod1;
        long long h2 = (hash2[r] - hash2[l] * pow2[r - l]) % mod2;
        if (h2 < 0) h2 += mod2;
        return {h1, h2};
    }

    long long size() const { return n; }
};
*/