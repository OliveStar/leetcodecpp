class Solution {
public:
    /**
    ** 算法：动态规划
    ** 用dp[i][j]表示字符串s的前i个字符和模式p的前j个字符是否能匹配
    ** 进行状态转移时，考虑模式p的第j个字符pj，与之对应的是字符串s中的第i个字符si
    ** 状态转移方程如下：
    ** dp[i][j] = dp[i-1][j-1]，si与pj相同或者pj是问号
    ** dp[i][j] = dp[i][j-1] | dp[i-1][j]，pj是星号
    ** dp[i][j] = false，其他情况
    ** 初始化状态如下：
    ** dp[0][0] = true，即当字符串s和模式p均为空时，匹配成功；
    ** dp[i][0] = false，即空模式无法匹配非空字符串；
    ** dp[0][j] 需要分情况讨论：因为星号才能匹配空字符串，所以只有当模式p的前j个字符均为星号时，dp[0][j]才为真
    ** 最终答案为dp[m][n]
    ** 时间复杂度：O(mn)，空间复杂度：O(mn)，即为存储所有(m+1)(n+1)元素的空间
    **/
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        dp[0][0] = true;
        for(int i = 1; i <= n; i++){
            if(p[i - 1] == '*'){
                dp[0][i] = true;
            }else{
                break;
            }
        }
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(p[j - 1] == '*'){
                    dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
                }else if(p[j - 1] == '?' || s[i - 1] == p[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};