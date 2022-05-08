class Solution {
public:
    bool isPossible(vector<int>& nums) {
        // freq记录每个元素出现的额次数，判断一个元素自己能否作为开头
        // need判断一个元素是否可以被接到其他序列的后面，[1,2,3,4]，[3,4]，元素5的need[5]=2
        // 元素优先判断自己是否能够接到其他序列后面
        unordered_map<int, int> freq, need;
        // 统计nums中元素的频率
        for(int v : nums) freq[v]++;

        for(int v : nums){
            if(freq[v] == 0){
                // 已经被用到其他子序列中
                continue;
            }
            // 先判断 v 是否能接到其他子序列后面
            if(need.count(v) && need[v] > 0){
                // v可以接到之前的某个序列后面
                freq[v]--;
                // 对v的需求减一
                need[v]--;
                // 对v+1的需求加一
                need[v+1]++;
            }else if(freq[v] > 0 && freq[v+1] > 0 && freq[v+2] > 0){
                // 将v作为开头，新建一个长度为3的子序列[v, v+1, v+2]
                freq[v]--;
                freq[v+1]--;
                freq[v+2]--;
                // 对v+3的需求加一
                need[v+3]++;
            }else{
                // 两种情况都不符合，则无法分配
                return false;
            }
        }

        return true;
    }
};