class Solution {
public:
    // 时间复杂度O(logn)，考虑二分查找法
    // 要找出target的上界和下界，分别用bgn、end和mid表示查找过程中的左端、右端和中点
    // 在找下界时，如果nums[mid]>=target，将end置为mid-1，否则将bgn置为mid+1，这样会逐渐接近target的下界，在循环结束时bgn就是target的下界
    // 在找上界时，如果nums[mid]>target，将end置为mid-1，否则将bgn置为mid+1，这样会逐渐接近target的上界，在循环结束时bgn在target的上界加1的位置。
    // 如果没有查找到target，上界和下界是一样的，以此来判断是否有target的存在。
    vector<int> searchRange(vector<int>& nums, int target) {
        int bgn = 0, end = nums.size()-1, mid, left, right;

        while(bgn <= end){
            mid = (bgn + end)/2;
            if(nums[mid] >= target)
                end = mid - 1;
            else
                bgn = mid + 1;
        }

        left = bgn;
        end = nums.size() - 1;
        
        while(bgn <= end){
            mid = (bgn + end)/2;
            if(nums[mid] > target)
                end = mid - 1;
            else
                bgn = mid + 1;
        }
        right = bgn;

        if(left == right)
            return vector<int>{-1, -1};
        else
            return vector<int>{left, right-1};
    }
};