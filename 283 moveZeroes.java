class Solution {
    // 将所有的0移到最后，其实就相当于移除nums中的所有0，然后再把后面的元素都赋值为0即可
    public void moveZeroes(int[] nums) {
        // 去除nums中的所有0，返回不含0的数组长度
        int p = removeElement(nums, 0);
        // 将nums[p...]的元素赋值为0
        for(;p < nums.length;p++){
            nums[p] = 0;
        }
    }

    int removeElement(int[] nums, int val){
        int fast = 0, slow = 0;
        while(fast < nums.length){
            if(nums[fast] != val){
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;
    }
}