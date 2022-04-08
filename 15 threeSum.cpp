class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        return threeSum(nums, 0);
    }

    /* 计算数组 nums 中所有和为target 的三元组 */
    vector<vector<int>> threeSum(vector<int>& nums, int target){
        // 数组得排个序
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        // 穷举threeSum的第一个数
        for(int i = 0; i < n; i++){
            // 对target-nums[i]计算twoSum
            vector<vector<int>> tuples = twoSumTarget(nums, i+1, target-nums[i]);
            // 如果存在满足条件的二元组，再加上nums[i]就是结果三元组
            for(vector<int>& tuple : tuples){
                tuple.push_back(nums[i]);
                res.push_back(tuple);
            }
            // 跳过第一个数字重复的情况，否则会出现重复结果
            // 例如nums=[1,1,1,2,3]，target=6
            // 用一个while循环来保证第一个元素不重复，后面两个数用twoSum函数保证不重复
            while(i < n-1 && nums[i] == nums[i+1]) i++;
        }
        return res;
    }

    /*从nums[start]开始，计算有序数组
     * nums中所有和为target的二元组 */
    vector<vector<int>> twoSumTarget(vector<int>& nums, int start, int target){
        // 左指针改为从start开始，其他不变
        int lo = start, hi = nums.size()-1;
        vector<vector<int>> res;
        while(lo < hi){
            int sum = nums[lo] + nums[hi];
            int left = nums[lo], right = nums[hi];
            if(sum < target){
                while(lo < hi && nums[lo] == left) lo++;
            }else if(sum > target){
                while(lo < hi && nums[hi] == right) hi--;
            }else{
                res.push_back({left, right});
                while(lo < hi && nums[lo] == left) lo++;
                while(lo < hi && nums[hi] == right) hi--;
            }
        }
        return res;
    }
};