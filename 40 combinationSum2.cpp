class Solution {
public:
    /**
    ** 由于数组元素可能重复且每个数字只能使用一次，所以在递归函数的循环中进入
    ** 下层递归时要将下标加1， 这样保证了每个数字只使用1次，而在39题中这里下标是不变的
    ** 另外数组中同一数字可能有多个，这样就要确保在同一层递归函数的for循环中只有第一个数字才会存入结果中，不然会出现重复的组合
    **/
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> rst;
        vector<int> curRst;

        sort(candidates.begin(), candidates.end());
        getSum(rst, curRst, candidates, 0, 0, target);

        return rst;
    }

    void getSum(vector<vector<int>> &rst, vector<int> &curRst, const vector<int>& candidates, int sum, int idx, int target){
        if(sum == target){
            rst.push_back(curRst);
        }
        else{
            for(int i = idx; i < candidates.size(); i++){
                if(sum + candidates[i] > target)
                    return;
                if(i != idx && candidates[i] == candidates[i-1])
                    continue;
                curRst.push_back(candidates[i]);
                getSum(rst, curRst, candidates, sum+candidates[i], i+1, target);
                curRst.pop_back();
            }
        }
    }
};