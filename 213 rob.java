class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        if(n == 1) return nums[0];
        // 第一间和最后一间房不能同时抢
        // 选择：要么抢第一间，要么抢最后一间（或者两间都不抢，但这种情况肯定不是最优解，排除）
        return Math.max(robRange(nums, 0, n-2), robRange(nums, 1, n-1));
    }

    int robRange(int[] nums, int start, int end){
        int n = nums.length;
        // 状态压缩
        int dp_front = 0, dp_tail = 0; // 两个变量分别存储相邻的房间最大值和隔一间房的最大值
        int dp_res = 0; // 当前房间的最大值
        // 自底向上动态规划
        for(int i = end; i >= start; i--){
            dp_res = Math.max(dp_front, nums[i] + dp_tail);
            dp_tail = dp_front;
            dp_front = dp_res;
        }
        return dp_res;
    }
}