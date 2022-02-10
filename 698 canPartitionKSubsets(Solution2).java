class Solution {
    public boolean canPartitionKSubsets(int[] nums, int k) {
        // 排除非法输入
        if(k > nums.length) return false;
        int sum = 0;
        for(int v : nums) sum+= v;
        if(sum % k != 0) return false;

        boolean[] used = new boolean[nums.length];
        int target = sum / k;
        // k号桶初始什么都没装，从nums[0]开始做选择
        return backtrack(k, 0, nums, 0, used, target);
    }

    boolean backtrack(int k, int bucket, int[] nums, int start, boolean[] used, int target){
        // base case
        if(k == 0){
            // 所有桶都被装满了，而且nums一定全部用完了
            // target == sum / k
            return true;
        }
        if(bucket == target){
            // 装满了当前桶，递归穷举下一个桶的选择
            // 让下一个桶从nums[0]开始选数字
            return backtrack(k-1, 0, nums, 0, used, target);
        }

        // 从start开始向后搜索有效的nums[i]装入当前桶
        for(int i = start; i < nums.length; i++){
            // 剪枝
            if(used[i]){
                // nums[i]已经被装入别的桶中
                continue;
            }
            if(nums[i] + bucket > target){
                // 当前桶装不下nums[i]
                continue;
            }
            // 做选择，将nums[i]装入当前桶中
            used[i] = true;
            bucket += nums[i];
            // 递归穷举下一个数字是否装入当前桶
            if(backtrack(k, bucket, nums, i+1, used, target)){
                return true;
            }
            // 撤销选择
            used[i] = false;
            bucket -= nums[i];
        }
        // 穷举了所有数字，都无法装满当前桶
        return false;
    }
}