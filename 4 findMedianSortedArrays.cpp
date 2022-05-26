class Solution {
public:
    // 中位数的作用是将一个集合划分为两个长度相等的子集，其中一个子集中的元素总是大于另一个子集中的元素
    // 算法：
    // 首先，在任意位置i将A划分成两个部分：left_A和right_A，A中有m个元素
    // 在任意位置j将B划分成两个部分：left_B和right_B，B中有n个元素
    // 将left_A和left_B放入一个集合left_part，将right_A和right_B放入一个集合right_part
    // 当A和B的总长度为偶数时，可以确认：len(left_part) = len(right_part)，且max(left_part) <= min(right_part),中位数就是前一部分的最大值和后一部分的最小值的平均值。
    // 当A和B的总长度为奇数时，可以确认：len(left_part) = len(right_part)+1，且max(left_part) <= min(right_part)，中位数就是前一部分的最大值
    // 因此我们可以对i在[0,m]的区间上进行二分搜索，找到最大的满足A[i-1]<=B[j]的i值，就得到了划分的方法，此时，划分前一部分元素中的最大值，以及划分后一部分元素中的最小值，才可能作为就是这两个数组的中位数。
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()){
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int left = 0, right = m;
        // median1：前一部分的最大值
        // median2：后一部分的最小值
        int median1 = 0, median2 = 0;

        while(left <= right){
            // 前一部分包含 nums1[0 ... i-1]和nums2[0 ... j-1]
            // 后一部分包含 nums1[i ... m-1]和nums2[j ... n-1]
            int i = (left + right) / 2;
            int j = (m+n+1)/2 - i;
            // nums_im1, nums_i, nums_jm1, nums_j 分别表示nums1[i-1],nums1[i], nums2[j-1], nums2[j]
            int nums_im1 = (i == 0? INT_MIN : nums1[i-1]);
            int nums_i = (i == m? INT_MAX : nums1[i]);
            int nums_jm1 = (j == 0? INT_MIN : nums2[j-1]);
            int nums_j = (j == n? INT_MAX : nums2[j]);

            if(nums_im1 <= nums_j){
                median1 = max(nums_im1, nums_jm1);
                median2 = min(nums_i, nums_j);
                left = i + 1;
            }else{
                right = i - 1;
            }
        }

        return (m + n) % 2 == 0 ? (median1 + median2) / 2.0 : median1;
    }
};