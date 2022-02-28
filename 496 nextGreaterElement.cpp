class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res1(nums1.size()); // 存放答案的数组
        vector<int> res2(nums2.size()); // 中间过程数组
        stack<int> s;
        // 倒着往栈里放
        for(int i = nums2.size()-1;i >= 0; i--){
            // 判定个子高矮
            while(!s.empty() && s.top() <= nums2[i]){
                // 矮个踢掉
                s.pop();
            }
            // nums2[i]身后的next great number
            res2[i] = s.empty()?-1:s.top();
            s.push(nums2[i]);
        }
        // 找出满足nums1[i] == nums2[j]的下标
        for(int i = 0; i < nums1.size(); i++){
            for(int j = 0; j < nums2.size();j++){
                if(nums1[i] == nums2[j]){
                    res1[i] = res2[j];
                    break;
                }
            }
        }
        return res1;
    }
};