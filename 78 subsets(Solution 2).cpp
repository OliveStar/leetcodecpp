class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // 记录走过的路径
        vector<int> track;
        backtrack(nums, 0, track);
        return res;
    }

    void backtrack(vector<int>& nums, int start, vector<int>& track){
        res.push_back(track);
        // i从start开始递增
        for(int i = start; i < nums.size(); i++){
            // 做选择
            track.push_back(nums[i]);
            // 回溯
            backtrack(nums, i+1, track);
            // 撤销选择
            track.pop_back();
        }
    }
};