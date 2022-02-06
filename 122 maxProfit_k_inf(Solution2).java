class Solution {
    // 空间复杂度优化版本
    // 交易次数k不限，k为正无穷，那么k和k-1就是一样的，不影响dp数组，可以降维
    public int maxProfit(int[] prices) {
        int n = prices.length;
        // dp_i_0 表示当前不持有股票的最大利润，dp_i_1表示当前持有股票的最大利润
        int dp_i_0 = 0, dp_i_1 = Integer.MIN_VALUE;
        for(int i = 0; i < n; i++){
            int temp = dp_i_0; // 临时变量存前一天的收益，等下dp_i_0就变化了
            dp_i_0 = Math.max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = Math.max(dp_i_1, temp - prices[i]);
        }
        return dp_i_0;
    }
}