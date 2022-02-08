class Solution {
    public int maxProfit(int max_k, int[] prices) {
        int n = prices.length;
        if(n <= 0){
            return 0;
        }

        if(max_k > n/2){
            // 一次交易由买入和卖出构成，至少需要两天，如果k>n/2，那么相当于k=inf
            // 有效的限制k应该不超过n/2
            // 交易次数k没有限制的情况
            return maxProfit_k_inf(prices);
        }

        // base case：
        // dp[-1][…][0] = d[…][0][0] = 0
        // dp[-1][…][1] = dp[…][0][1] = -inf
        int[][][] dp = new int[n][max_k+1][2];
        // max_k = 0时的base case
        for(int i = 0; i < n; i++){
            dp[i][0][0] = 0;
            dp[i][0][1] = Integer.MIN_VALUE;
        }
        
        for(int i = 0; i < n; i++)
            for(int k = max_k; k >= 1; k--){
                if(i - 1 == -1){
                    // 处理i=-1时的base case
                    dp[i][k][0] = 0;
                    dp[i][k][1] = -prices[i];
                    continue;
                }
                dp[i][k][0] = Math.max(dp[i-1][k][0], dp[i-1][k][1]+prices[i]);
                dp[i][k][1] = Math.max(dp[i-1][k][1], dp[i-1][k-1][0]-prices[i]);
        }
        
        return dp[n-1][max_k][0];
    }

    // 交易次数k不限，k为正无穷，那么k和k-1就是一样的，不影响dp数组，可以降维
    public int maxProfit_k_inf(int[] prices) {
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