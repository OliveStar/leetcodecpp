class Solution {
public:
    /**
    算法：逆向双指针法
    nums1后半部分是空的，可以直接覆盖，不会影响结果，可以将指针设置为从后向前遍历
    每次取两者之中的较大者放进nums1的最后面
    **/
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1  = m - 1, p2 = n - 1;
        int tail = m + n - 1;
        int cur;
        while(p1 >= 0 || p2 >= 0){
            if(p1 == -1){
                cur = nums2[p2--];
            }else if(p2 == -1){
                cur = nums1[p1--];
            }else if(nums1[p1] > nums2[p2]){
                cur = nums1[p1--];
            }else{
                cur = nums2[p2--];
            }
            nums1[tail--] = cur;
        }
    }
};