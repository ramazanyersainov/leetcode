class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        int m = grid[0].size();
        
        int k,l;
        
        vector<vector<int>> dp(n, vector<int> (m, 0) );
        
        dp[0][0] = grid[0][0];
        for (int i = 0; i < n; ++i) {
            
            for (int j = 0; j < m; ++ j) {
                
                if (!i) {
                    if (!i && !j)
                        continue;
                    dp[i][j] = grid[i][j] + dp[i][j-1];
                    continue;
                }
                else
                    k = dp[i-1][j];
                
                if (!j) {
                    dp[i][j] = grid[i][j] + dp[i-1][j];
                    continue;
                }
                else
                    l = dp[i][j-1];
                
                dp[i][j] = grid[i][j] + std::min(k,l);
                
            }
            
        }
        
        return dp[n-1][m-1];
    }
};