class Solution {
public:
    int maximumLength(string &s) {
        unordered_map<string,int> mp;
        int n = s.length(), len = -1;
        for (int i = 0; i < n; i++) {
            string cur = "";
            for (int j = i; j < n; j++) {
                if (s[j] != s[i]) break;      // stop once character changes
                cur += s[j];
                mp[cur]++;
            }
        }
        for (auto &x : mp) {
            if (x.second >= 3 && (int)x.first.length() > len)
                len = x.first.length();
        }
        return len;
    }
};