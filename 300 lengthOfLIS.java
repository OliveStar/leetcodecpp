class Solution {
    public int lengthOfLIS(int[] nums) {
        int[] dp = new int[nums.length];
        // base case：dp 数组全都初始化为 1
        Arrays.fill(dp, 1);
        // 状态转移方程：数学归纳法，假设dp[i-1]是nums[0...i-1]中的最长子序列的长度，求dp[i]的长度
        // 找到前面那些结尾比nums[i]小的子序列，选择其中最长的子序列，然后把nums[i]接到最后，就可以形成一个新的最长递增子序列，而且这个新的子序列长度加一
        // 也就是dp[i]的值
        for(int i = 0; i < nums.length;i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j])
                    dp[i] = Math.max(dp[i], dp[j]+1);
            }
        }
        // 最终结果（子序列的最大长度）应该是 dp 数组中的最大值
        int res = 0;
        for(int i=0; i < dp.length; i++)
            res = Math.max(res, dp[i]);
        return res;
    }
}