class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        stack<int> s;
        // 假装数组长度翻倍了
        for(int i = n*2-1; i >= 0; i--){
            // 索引要求模，其他的和模板一样
            while(!s.empty() && s.top() <= nums[i%n]){
                s.pop();
            }
            res[i % n] = s.empty()? -1 : s.top();
            s.push(nums[i % n]);
        }
        return res;
    }
};