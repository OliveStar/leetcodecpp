class Solution {
public:
    /**
        算法：双指针。
        我们定义两个指针slow 和 fast 分别为慢指针和快指针，其中慢指针表示处理出的数组的长度，快指针表示已经检查过的数组的长度，即 nums[fast] 表示待检查的第一个元素，nums[slow−1] 为上一个应该被保留的元素所移动到的指定位置。
        我们可以扩展此题的通用解法
        因为本题要求相同元素最多出现k次，所以我们需要检查前k个应该被保留的元素nums[slow−k] 是否和当前待检查元素 nums[fast] 相同。当且仅当 nums[slow−k]=nums[fast] 时，当前待检查元素 nums[fast] 不应该被保留（因为此时必然有 nums[slow−k]=nums[slow−k+1] = ... =nums[fast]）。最后，slow 即为处理好的数组的长度。
        由于输入数组有序，因此，前k个数组元素不需要处理。
        时间复杂度：O(n)，其中 n 是数组的长度。我们最多遍历该数组一次。
        空间复杂度：O(1)。我们只需要常数的空间存储若干变量。
    **/
    
    int process(vector<int>& nums, int k){
        int n = nums.size();
        int slow = 0, fast = 0;
        while(fast < n){
            if(slow < k || nums[slow - k] != nums[fast]){
                nums[slow++] = nums[fast];
            }
            fast++;
        }
        return slow;
    }

    int removeDuplicates(vector<int>& nums) {
        return process(nums, 2);
    }
};