class Solution {
    public int minPathSum(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        // dp数组定义为：从[0][0]到[i][j]所经过的路径的最小和
        int[][] dp = new int[m][n];
        // base case
        dp[0][0] = grid[0][0];
        // dp[0…i][0] = sum{grid[0…i][0]}
        for(int i = 1;i < m;i++)
            dp[i][0] = dp[i-1][0] + grid[i][0];
        // dp[0][0…j] = sum{grid[0][0…j]}
        for(int j = 1;j < n;j++)
            dp[0][j] = dp[0][j-1] + grid[0][j];
        // dp[i][j] = min{dp[i-1][j],dp[i][j-1]} + grid[i][j]
        for(int i = 1;i < m;i++)
            for(int j = 1;j < n;j++)
                dp[i][j] = Math.min(dp[i-1][j],dp[i][j-1]) + grid[i][j];
        return dp[m-1][n-1];
    }
}