// 如果想高效地，等概率地随机获取元素，就要使用数组作为底层容器
// 如果要保持数组元素的紧凑性，可以把待删除元素换到最后，然后pop掉末尾的元素，实现时间复杂度达到O(1)，我们需要额外的哈希表记录值到索引的映射
// 数组中含有空洞（黑名单数字），也可以利用哈希表巧妙处理映射关系，让数组在逻辑上是紧凑的，方便随机取元素。
class Solution {
public:
    int sz;
    unordered_map<int, int> mapping;

    // 构造函数
    Solution(int N, vector<int>& blacklist) {
        sz = N - blacklist.size();
        // 先将所有黑名单数字加入map
        for(int b : blacklist){
            // 这里赋值多少都可以
            // 目的仅仅是把键存进哈希表
            // 方便快速判断数字是否在黑名单内
            mapping[b] = 666;
        }

        int last = N - 1;
        for(int b : blacklist){
            // 如果b已经在区间[sz, N]
            // 可以直接忽略
            if(b >= sz){
                continue;
            }
            // 跳过所有黑名单中的数字
            while(mapping.count(last)){
                last--;
            }
            // 将黑名单中的索引映射到合法数字，换到最后去
            mapping[b] = last;
            last--;
        }
    }
    
    int pick() {
        // 随机选取一个索引
        int index = rand() % sz;
        // 这个索引命中了黑名单，
        // 需要被映射到其他位置
        if(mapping.count(index)){
            return mapping[index];
        }
        // 若没命中黑名单，则直接返回
        return index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */