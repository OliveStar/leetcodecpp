// 由于数组已经排序，重复的元素一定连在一起，找出它们并不难
// 如果梅找到一个重复元素就立即原地删除它，由于数组中删除元素涉及数组搬移，整个时间复杂度会达到O(N^2)
class Solution {
    public int removeDuplicates(int[] nums) {
        if(nums.length == 0){
            return 0;
        }
        int slow = 0, fast = 0;
        // 让慢指针slow走在后面，快指针fast走在前面，找到一个不重复的元素就赋值给slow并让slow前进一步
        while(fast < nums.length){
            if(nums[fast] != nums[slow]){
                slow++;
                nums[slow] = nums[fast];
            }
            fast++;
        }
        // 保证了nums[0…slow]都是无重复的元素
        // 当fast指针遍历完整个数组nums后，nums[0…slow]就是整个数组去重之后的结果
        // 数组长度为索引+1
        return slow+1;
    }
}