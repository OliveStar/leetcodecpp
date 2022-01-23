// 516.最长回文子序列
// 算法说明：
// dp数组定义：在子串s[i…j]中，最长回文子序列的长度为dp[i][j]
// 假设s[i+1…j-1]已经是回文子序列，判断s[i]和s[j]的字符
// 如果它俩相等，那么它俩加上s[i+1…j-1]中的最长回文子序列就是s[i…j]的最长回文子序列
// 如果它俩不相等，说明它俩不可能同时出现在s[i…j]的最长回文子序列中，那么把它俩分别加入s[i+1…j-1]中，看看哪个字符串产生的回文子序列更长
// 子串中s(i…j)i必定小于j，所以[i][j]，i > j的情况是无意义的，赋值为0。
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        // dp数组全部初始化为0
        vector<vector<int> > dp(n,vector<int>(n,0));
        // base case:单字符为回文子序列
        for(int i=0; i < n; i++)
            dp[i][i] = 1;
        // 反着遍历保证正确的状态转移
        for(int i = n-1; i >= 0; i--){
            for(int j = i+1; j < n; j++){
                // 状态转移方程
                if(s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1]+2;
                else
                    dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
            }
        }
        // 整个s的最长回文子序列长度
        return dp[0][n-1];
    }
};