class Solution {
    // 字符 -> 索引列表
    unordered_map<char, vector<int>> charToIndex;
    // 备忘录
    vector<vector<int>> memo;
    /* 主函数 */
    public:
    int findRotateSteps(string ring, string key) {
        int m = ring.size();
        int n = key.size();
        // 备忘录全部初始化为 0
        memo.resize(m, vector<int>(n,0));
        // 记录圆环上字符到索引的映射
        for(int i = 0; i < ring.size(); i++){
            charToIndex[ring[i]].push_back(i);
        }
        // 圆盘指针最初指向12点钟方向
        // 从第一个字符开始输入key
        return dp(ring, 0, key, 0);
    }

    // 计算圆盘指针再ring[i]，输入key[j…]的最少操作数
    int dp(string& ring, int i, string& key, int j){
        // base case 完成输入
        if(j == key.size()) return 0;
        // 查找备忘录，避免重叠子问题
        if(memo[i][j] != 0) return memo[i][j];

        int n = ring.size();
        // 做选择
        int res = INT_MAX;
        // ring上可能有多个字符key[j]
        for(int k : charToIndex[key[j]]){
            // 拨动指针的次数
            int delta = abs(k - i);
            // 选择顺时针还是逆时针
            delta = min(delta, n - delta);
            // 将指针拨到right[k]，继续输入key[j+1…]
            int subProblem = dp(ring, k, key, j + 1);
            // 选择整体操作次数最少的
            // 加一是因为按动操作按钮也是一次操作
            res = min(res, 1 + delta + subProblem);
        }
        // 将结果存入备忘录
        memo[i][j] = res;
        return res;
    }
};