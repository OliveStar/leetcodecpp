class NumMatrix {
    // preSum[i][j] 记录矩阵[0,0,i,j]
    private int[][] preSum;

    public NumMatrix(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        if(m == 0 || n == 0) return;
        // 构造前缀和矩阵
        preSum = new int[m+1][n+1];
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                // 计算每个矩阵[0,0,i,j]的元素和
                preSum[i][j] = preSum[i-1][j] + preSum[i][j-1] + matrix[i-1][j-1] - preSum[i-1][j-1];
            }
        }
    }
    
    // 计算子矩阵 [x1, y1, x2, y2]的元素和
    public int sumRegion(int row1, int col1, int row2, int col2) {
        // 目标矩阵之和由四个相邻矩阵运算获得
        return preSum[row2+1][col2+1] - preSum[row1][col2+1] - preSum[row2+1][col1] + preSum[row1][col1];
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */