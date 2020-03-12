class Solution {
public:
    unordered_map< string, unordered_map<string, bool> > memo;
    bool isMatch(string s, string p) {
        
        bool dp[s.size() + 1][p.size() + 1];
        dp[0][0] = true;
        for (int i = 1; i < s.size() + 1; ++ i) {
            dp[i][0] = false;
        }
        int j = 1;
        while (p[j - 1] == '*' && j < p.size() + 1) {
            dp[0][j] = true;
            ++ j;
        }
        while (j < p.size() + 1) {
            dp[0][j] = false;
            ++ j;
        }
        for (int i = 1; i < s.size() + 1; ++ i) {
            for (int j = 1; j < p.size() + 1; ++ j) {
                if (p[j-1] == '*') {
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
                } else if (p[j-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1]);
                }
            }
        }
        
        return dp[s.size()][p.size()];
    }
    
};