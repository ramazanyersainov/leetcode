class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map <int, set<char>> rows;
        unordered_map <int, set<char>> cols;
        unordered_map <int, set<char>> boxes;
        
        for (int i = 0; i < board.size(); ++ i) {
            
            for (int j = 0; j < board[0].size(); ++ j) {
                
                if (board[i][j] != '.') {
                    
                    if (!rows[i].insert(board[i][j]).second or !cols[j].insert(board[i][j]).second or !boxes[i/3 + (j/3)*3].insert(board[i][j]).second) {
                        
                        return false;
                        
                    }
                    
                }
                
            }
            
        }
        
        return true;
    }
};