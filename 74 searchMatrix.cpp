class Solution {
public:
    /**
    算法：每行都已排好序并且每行第一个数字大于上一行最后一个数字，整个二维数组可以被看作一个有序的一维数组进行二分查找
    时间复杂度：O（m*n）
    **/
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())
            return false;
        int row = matrix.size(), col = matrix[0].size();
        int bgn = 0, end = row * col - 1, mid;

        while(bgn <= end){
            mid = (bgn + end) / 2;
            if(matrix[mid/col][mid%col] == target)
                return true;
            else if(matrix[mid/col][mid%col] > target)
                end = mid - 1;
            else
                bgn = mid + 1;
        }

        return false;
    }
};