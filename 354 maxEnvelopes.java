class Solution {
    public int maxEnvelopes(int[][] envelopes) {
        int n = envelopes.length;
        // 按宽度升序排列，如果宽度一样，则按高度降序排列
        // 因为两个宽度相同的信封不能相互包含的，逆序排序保证在 w 相同的数对中最多只选取一个。
        Arrays.sort(envelopes, new Comparator<int[]>(){
            public int compare(int[] a, int[] b){
                return a[0] == b[0]? b[1]-a[1] : a[0]-b[0];
            }
        });
        // 对高度数组寻找LIS
        int[] height = new int[n];
        for(int i = 0; i < n; i++)
            height[i] = envelopes[i][1];
        return lengthOfLIS(height);
    }

    int lengthOfLIS(int[] nums){
        int n = nums.length;
        //dp[i]定义为以nums[i]为结尾的最长递增子序列的长度
        int[] dp = new int[n];
        Arrays.fill(dp, 1);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j])
                    dp[i] = Math.max(dp[i], dp[j]+1);
            }
        int res = 0;
        for(int i = 0; i < n; i++){
            res = Math.max(res, dp[i]);
        }
        return res;
    }
}