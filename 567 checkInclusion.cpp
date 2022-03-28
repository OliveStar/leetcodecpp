class Solution {
public:
    // 判断s中是否存在t的排列
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need, window;
        for(char c : s1) need[c]++;

        int left = 0, right = 0;
        int valid = 0;
        while(right < s2.size()){
            char c = s2[right];
            right++;
            // 进行窗口内数据的一系列更新
            if(need.count(c)){
                window[c]++;
                if(window[c] == need[c])
                    valid++;
            }

            // 判断左侧窗口是否要收缩：当窗口大小大于t.size时，缩小窗口，排列需要长度相同
            while(right - left >= s1.size()){
                // 在这里判断是否找到了合法的子串
                if(valid == need.size())
                    return true; // 找到一个合法的排列，就立即返回true
                char d = s2[left];
                left++;
                // 进行窗口内数据的一系列更新
                if(need.count(d)){
                    if(window[d] == need[d])
                        valid--;
                    window[d]--;
                }
            }
        }

        // 未找到符合条件的子串
        return false;
    }
};