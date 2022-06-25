class Solution {
    bool isExist(const vector<vector<char>>& board, vector<vector<bool>>& isUsed, const string& word, int idx, int r, int c){
        if(!isUsed[r][c] && board[r][c] == word[idx]){
            if(idx == word.size() - 1) return true;
            isUsed[r][c] = true;
            if(r > 0){
                if(isExist(board, isUsed, word, idx+1, r-1, c))
                    return true;
            }
            if(r < board.size() - 1){
                if(isExist(board, isUsed, word, idx+1, r+1, c))
                    return true;
            }
            if(c > 0){
                if(isExist(board, isUsed, word, idx+1, r, c-1))
                    return true;
            }
            if(c < board[0].size() - 1){
                if(isExist(board, isUsed, word, idx+1, r, c+1))
                    return true;
            }
            isUsed[r][c] = false;
            return false;
        }
        else
            return false;
    }
public:
    // 算法：典型的回溯法
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        if(!row) return false;
        int col = board[0].size();
        if(!col) return false;
        vector<vector<bool>> isUsed(row, vector<bool>(col, false));

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(isExist(board, isUsed, word, 0, i, j))
                    return true;
            }
        }

        return false;
    }
};