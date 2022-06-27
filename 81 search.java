class Solution {
    /** 
        算法：二分查找
        本题为33 搜索旋转排序数组的进阶版，因为数组中存在重复元素，所以无法通过二分法查找到旋转点
        所谓的旋转是“将某个下标前面的所有数整体移到后面，使得数组从整体有序变为分段有序”
        二分的本质是“二段性”，只要一段满足某个性质，另外一段不满足某个性质，就可以用二分
        如果相同元素使旋转点产生了分裂，就会让数组失去二段性
        所以我们需要进行预处理操作，将新数组尾部与nums[0]相同的元素忽略，使其二段性恢复
        时间复杂度：恢复二段性处理中，最坏的情况下（考虑整个数组都是同一个数）复杂度是 O(n)，而之后的找旋转点和目标值都是「二分」，复杂度为 O(logn)。整体复杂度为 O(n) 的。
        空间复杂度：O(1)。
    */
    public boolean search(int[] nums, int target) {
        int n = nums.length;
        int l = 0, r = n - 1;
        // 恢复二段性
        while(l < r && nums[0] == nums[r]) r--;

        // 第一次二分，找旋转点
        while(l < r){
            // 不+1的话会导致死循环。l = mid 这种下取整，到区间只剩2个元素的时候，区间无法缩小
            int mid = l + r + 1 >> 1;
            /* 左端点小于中点，说明左半部分完全有序 */
            if(nums[mid] >= nums[0]){
                l = mid;
            }else{
                /* 中点小于右端点，说明右半部分完全有序 */
                r = mid - 1;
            }
        }

        int idx = n;
        if(nums[r] >= nums[0] && r + 1 < n) idx = r + 1;

        // 第二次二分，找目标值
        // 左半部分查找目标值
        int ans = find(nums, 0, idx - 1, target);
        if(ans != -1) return true;
        // 右半部分查找目标值
        ans = find(nums, idx, n - 1, target);
        return ans != -1;
    }

    int find(int[] nums, int l, int r, int target){
        while(l < r){
            int mid = l + r >> 1;
            if(nums[mid] >= target){
                r = mid;
            }else{
                l = mid + 1; 
            }
        }
        return nums[r] == target ? r : -1;
    }


}