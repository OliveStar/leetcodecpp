class Solution {
    public int maxSubArray(int[] nums) {
        //dp数组定义：以 nums[i] 为结尾的「最大子数组和」为 dp[i]
        int[] dp = new int[nums.length];
        dp[0] = nums[0];
        for(int i=1;i < nums.length;i++){
            dp[i] = Math.max(dp[i-1]+nums[i], nums[i]);
        }
        int res = Integer.MIN_VALUE;
        // 按照我们当前 dp 数组定义，并不能保证 nums[0..i] 中的最大子数组与 nums[i+1] 是相邻的
        // 想得到整个 nums 数组的「最大子数组和」，不能直接返回 dp[n-1]，而需要遍历整个 dp 数组
        for(int i = 0;i < dp.length;i++){
            res = Math.max(res, dp[i]);
        }
        return res;
    }
}