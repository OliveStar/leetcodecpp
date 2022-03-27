class Solution {
public:
    string minWindow(string s, string t) {
        // 初始化window和need两个哈希表，记录窗口中的字符和需要凑齐的字符
        unordered_map<char, int> need, window;
        for(char c : t) need[c]++;
        // 使用left和right变量初始化窗口的两端，区间[left, right)是左闭右开的，初始情况不包含任何元素
        int left = 0, right = 0;
        int valid = 0; // valid变量表示窗口中满足need条件的字符个数
        // 记录最小覆盖子串的起始索引及长度
        int start = 0, len = INT_MAX;
        while(right < s.size()){
            // c是将移入窗口的字符
            char c = s[right];
            // 右移窗口
            right++;
            // 进行窗口数据的一系列更新
            if(need.count(c)){
                window[c]++;
                if(window[c] == need[c])
                    valid++;
            }

            // 判断左侧窗口是否要收缩
            // 如果valid和need.size的大小相同，说明窗口已经满足条件，已经完全覆盖了串T
            while(valid == need.size()){
                // 在这里更新最小覆盖子串
                if(right - left < len){
                    start = left;
                    len = right - left;
                }
                // d是将移出窗口的字符
                char d = s[left];
                // 左移窗口
                left++;
                // 进行窗口内数据的一系列更新
                if(need.count(d)){
                    if(window[d] == need[d])
                        valid--;
                    window[d]--;
                }
            }
        }
        // 返回最小覆盖子串
        return len == INT_MAX? "" : s.substr(start, len);
    }
};