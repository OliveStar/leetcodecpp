class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> combine(int n, int k) {
        if(k <= 0 || n <= 0) return res;
        vector<int> track;
        backtrack(n, k, 1, track);
        return res;
    }

    void backtrack(int n, int k, int start, vector<int>& track){
        // 到达回溯树的底部
        if(k == track.size()){
            res.push_back(track);
            return;
        }
        // i从start开始递增
        for(int i = start; i <= n; i++){
            // 做选择
            track.push_back(i);
            backtrack(n, k, i+1, track);
            // 撤销选择
            track.pop_back();
        }
    }
};