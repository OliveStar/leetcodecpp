class Solution {
public:
    /**
    算法：
    我们可以用矩阵的第一行和第一列代替方法一中的两个标记数组，以达到 O(1)的额外空间。但这样会导致原数组的第一行和第一列被修改，无法记录它们是否原本包含 0。因此我们需要额外使用两个标记变量分别记录第一行和第一列是否原本包含 0。
    在实际代码中，我们首先预处理出两个标记变量，接着使用其他行与列去处理第一行与第一列，然后反过来使用第一行与第一列去更新其他行与列，最后使用两个标记变量更新第一行与第一列即可。
    我们首先遍历该数组一次，如果某个元素为0，那么就将该元素所在的行和列所对应标记数组的位置置为true。   
    最后我们再次遍历该数组，用标记数组更新原数组即可。
    时间复杂度O(mn)，其中m 是矩阵的行数，n 是矩阵的列数。我们至多只需要遍历该矩阵两次。
    空间复杂度O（1），我们只需要常数空间存储若干变量。
    */
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int flag_col0 = false, flag_row0 = false;
        for(int i = 0; i < m; i++){
            if(!matrix[i][0]){
                flag_col0 = true;
            }
        }
        for(int j = 0; j < n; j++){
            if(!matrix[0][j]){
                flag_row0 = true;
            }
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(!matrix[i][j]){
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(!matrix[i][0] || !matrix[0][j]){
                    matrix[i][j] = 0;
                }
            }
        }
        if(flag_col0){
            for(int i = 0; i < m; i++){
                matrix[i][0] = 0;
            }
        }
        if(flag_row0){
            for(int j = 0; j < n; j++){
                matrix[0][j] = 0;
            }
        }
    }
};