class Solution {
public:
    /*
        算法：如果从第n个数字到最后都是递减的，并且第n-1个数字小于第n个
        说明从第n个数字开始的这段序列是字典序组合的最后一个，在下一个组合中他们要倒序变为字典序第一个
        然后从这段序列中找出第一个大于第n-1个数字的数和第n-1个数字交换即可
        举例：当前排列为12431，431为递减部分，同时4>2，我们把431倒序，组合变为12134
        然后从134中找出第一个大于2的数字和2交换，得到下一个组合13124
        对于完全递减的排列例如4321在倒序之后就返回结束了。
    */
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;
        while(i > 0 && nums[i] <= nums[i-1]) i--;
        reverse(nums.begin()+i, nums.end());
        if(i == 0) return;
        for(int j = i; j < nums.size(); j++){
            if(nums[j] > nums[i-1]){
                swap(nums[i-1], nums[j]);
                break;
            }
        }
    }
};