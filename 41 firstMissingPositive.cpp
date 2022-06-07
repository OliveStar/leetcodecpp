class Solution {
public:
    /**
    ** 算法：恢复后，数组应当有[1,2,3,…, N]的形式，但其中有若干位是错误的，最先出现的错误位就是答案
    ** 如何恢复数组？对数组进行一次遍历，遍历到的数x=nums[i]，如果x在[1,N]中，x应当出现在数组中的x-1位置，交换nums[i]和nums[x-1]，x就出现在了正确的位置
    ** 新的nums[i]还可能在[1,N]中，需要继续交换直到nums[i]不在[1,N]中
    ** 如果nums[i] == nums[x-1]，会陷入死循环，需要增加判断条件跳出循环,开始遍历下一个数
    ** 时间复杂度：每次交换都会把一个数交换到正确的位置，交换的次数最多为N，时间复杂度O(N)
    **/
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            while(nums[i] > 0 && nums[i] <= n && nums[nums[i]-1] != nums[i]){
                swap(nums[nums[i]-1], nums[i]);
            }
        }
        for(int i = 0; i < n; i++){
            if(nums[i] != i+1){
                return i + 1;
            }
        }
        return n + 1;
    }
};