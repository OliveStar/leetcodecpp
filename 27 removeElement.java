class Solution {
    // 快慢指针
    // 如果fast遇到值为val的元素，则直接跳过
    // 否则赋值给slow指针，并让slow前进一步
    public int removeElement(int[] nums, int val) {
        int fast = 0, slow = 0;
        while(fast < nums.length){
            if(nums[fast] != val){
                // 与有序数组去重不同，此处是先赋值再自增
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow; // nums[0...slow-1]是不包含值为val的元素的，结果数组长度就是slow
    }
}