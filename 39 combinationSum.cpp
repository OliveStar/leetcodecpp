class Solution {
void getSum(const vector<int>& candidates, int target, vector<vector<int>>& rst, vector<int>& curRst, int sum, int idx){
    if(sum == target){
        rst.push_back(curRst);
    }
    else{
        for(int i = idx; i < candidates.size(); i++){
            if(sum + candidates[i] > target)
                return;
            curRst.push_back(candidates[i]);
            getSum(candidates, target, rst, curRst, sum + candidates[i], i);
            curRst.pop_back();
        }
    }
}

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> rst;
        vector<int> curRst;
        sort(candidates.begin(), candidates.end());
        getSum(candidates, target, rst, curRst, 0, 0);
        return rst;
    }
};