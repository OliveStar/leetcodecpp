class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        // i 和 end 标记了可以选择的跳跃步数
        // farthest 标记了所有选择 [i..end] 中能够跳到的最远距离
        // jumps 记录了跳跃次数
        int end = 0, farthest = 0;
        int jumps = 0;
        for(int i = 0; i < n-1; i++){
            farthest = max(farthest, nums[i]+i);
            if(end == i){
                jumps++;
                end = farthest;
            }
        }
        return jumps;
    }
};