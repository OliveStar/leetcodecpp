class Solution {
public:
    // 算法：分类讨论，二分查找
    /*
        在前后两端颠倒后的有序数组中查找给定值
        分别用l、m、r表示二分查找过程中左端、中间和右端的元素下标
        如果target == nums[m]，查找结束
        如果target > nums[m]，分为三种情况：
            如果target > nums[l]，需比较nums[m]和nums[l]：
                若nums[m] >= nums[l]，表明目标值在后半段，将l置为m+1;
                若nums[m] < nums[l]，表明目标值在前半段，将r置为m-1;
            如果target < nums[l]，此时只有一种情况，目标值在后半段，将l置为m+1。
            如果target == nums[l]，则查找结束
        如果target < nums[m]，分为三种情况：
            如果target < nums[l]，需比较nums[m]和nums[l]：
                若nums[m] >= nums[l]，表明目标值在后半段，将l置为m+1;
                若nums[m] < nums[l]，表明目标值在前半段，将r置为m-1;
            如果target > nums[l]，目标值在前半段，将r置为m-1；
            如果target == nums[l]，则查找结束
        如果循环结束没有找到，则查找结束
    */
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1, m;
        while(l <= r){
            m = (l+r)/2;
            if(target == nums[m])
                return m;
            else if(target > nums[m]){
                if(target > nums[l]){
                    if(nums[m] >= nums[l])
                        l = m + 1;
                    else
                        r = m - 1;
                }
                else if(target < nums[l])
                    l = m + 1;
                else
                    return l;
            }
            else{
                if(target < nums[l]){
                    if(nums[m] >= nums[l])
                        l = m + 1;
                    else
                        r = m - 1;
                }
                else if(target > nums[l])
                    r = m - 1;
                else
                    return l;
            }
        }
        return -1;
    }
};