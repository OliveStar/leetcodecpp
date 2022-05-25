class Solution {
public:
    // 判断每行、每列、每个小的九宫格中是否有重复的数字
    // 用HashTable来存储已经出现过的数字
    // c++ unordered_set容器，容器内部存储的元素的值各不相同，即天然去重。
    // 不同于set，unordered_set不再以键值对的形式存储数据，而是直接存储数据的值。
    // unordered_set的成员方法：
    // begin():返回指向容器中第一个元素的正向迭代器
    // end():返回指向容器中最后一个元素之后位置的迭代器
    // find(key):查找值为key的元素，如果找到，则返回一个指向该元素的正向迭代器；如果没找到，则返回一个与end()方法相同的迭代器
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9), cols(9), grid(9);
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                // 跳过空格
                if(board[i][j] == '.')
                    continue;
                // 有重复元素，不是有效的数独填充
                if(rows[i].find(board[i][j]) != rows[i].end())
                    return false;
                else
                    rows[i].insert(board[i][j]);
                if(cols[j].find(board[i][j]) != cols[j].end())
                    return false;
                else
                    cols[j].insert(board[i][j]);
                int n = i - i%3 + j/3; // 二维坐标映射一维
                if(grid[n].find(board[i][j]) != grid[n].end())
                    return false;
                else
                    grid[n].insert(board[i][j]);
                
            }
        }
        return true;
    }
};