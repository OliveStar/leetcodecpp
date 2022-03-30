class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;
        
        int left = 0, right = 0;
        int res = 0; // 记录结果
        while(right < s.size()){
            char c = s[right];
            right++;
            // 进行窗口内数据的一系列更新
            window[c]++;
            // 判断左侧窗口是否要收缩：存在重复元素时收缩
            while(window[c] > 1){
                char d = s[left];
                left++;
                // 进行窗口内数据的一系列更新
                window[d]--;
            }
            // 在收缩窗口完成后更新res，收缩完成后一定保证窗口中没有重复
            res = max(res, right - left);
        }
        return res;
    }
};