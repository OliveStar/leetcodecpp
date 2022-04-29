class Solution {
public:
    // 时间复杂度 O(N)
    // 空间复杂度 O(1)
    // 算法：不使用额外空间判断某个索引有多少个元素对应
    // 将nums中的元素变为[0…N-1]，每个元素和一个数组索引完全对应
    // 元素重复，会有两个数对应到一个索引；元素缺失，会有一个索引没有对应的元素
    // 通过将每个索引对应的元素变成负数，以表示这个索引被对应过一次了
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int dup = -1;
        for(int i = 0; i < n; i++){
            int index = abs(nums[i]) - 1;
            // nums[index] 小于0 说明重复访问
            if(nums[index] < 0)
                dup = abs(nums[i]);
            else
                nums[index] *= -1;
        }

        int missing = -1;
        for(int i = 0; i < n; i++)
            // nums[i] 大于0 则说明没有访问
            if(nums[i] > 0)
                missing = i + 1;
        
        return {dup, missing};
    }
};