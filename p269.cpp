class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (k > s.size()) return false;
        int x = 0;
        for (int i = 0; i < k; ++i) {
            x <<= 1;
            x += (s[i] == '1');
        }
        bool a[1<<k];
        memset(a, 0, sizeof a);
        a[x] = true;
        for (int i = k; i < s.size(); ++i) {
            x <<= 1;
            if (x >= (1 << k)) x -= (1 << k);
            x += (s[i] == '1');
            a[x] = true;
        }
        for (int j = 0; j < (1 << k); ++j)
            if (a[j] == false) return false;
        return true;
    }
};