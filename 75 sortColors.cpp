class Solution {
public:
    // 算法：原地排序，每遍历一个元素，查看它的值：
    // 如果为0，将它与前端所有0的下一个元素（pos0）互换
    // 如果为2，将它与后端所有2的上一个元素（pos2）互换
    // 如果为1，接着遍历下一个元素。
    // 需要记录下当前已排好序的0和2排到了哪里，遍历到pos2之后即完成排序。
    void sortColors(vector<int>& nums) {
        int pos0 = 0, pos2 = nums.size() - 1, cur = 0;
        while(pos2 >= 0 && nums[pos2] == 2)
            pos2--;
        
        // 当前元素和pos2互换时，pos2上元素为0或1
        // 交换后需要对当前元素进行一次判断才能遍历下一个元素
        while(cur <= pos2){
            // 当前元素和pos0元素互换时，pos0位置上必定为1
            if(nums[cur] == 0){
                nums[cur++] = 1;
                nums[pos0++] = 0;
            }
            else if(nums[cur] == 2){
                nums[cur] = nums[pos2];
                nums[pos2--] = 2;
                while(pos2 >= 0 && nums[pos2] == 2)
                    pos2--;
            }
            else{
                cur++;
            }
        }
    }
};