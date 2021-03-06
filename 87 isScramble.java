class Solution {
    /**
        算法：区间DP
        给定两个字符串T和S，假设T是由S变换而来
        1）如果T和S长度不一样，必定不能变来
        2) 如果长度一样，顶层字符串S能够划分为S1和S2，同样字符串T也能够划分为T1和T2
            情况一：没交换，S1 ==> T1，S2 ==> T2
            情况二：交换了，S1 ==> T2，S2 ==> T1
        子问题就是分别讨论两种情况：1）T1是否由S1变来，T2是否由S2变来；2）T1是否由S2变来，T2是否由S1变来
        状态编码：
        dp[i][j][k][h]表示T[k...h]是否由S[i...j]变来。由于变换必须长度是一样的，因此这边有个关系j-i=h-k，可以把四维数组降成三维。
        dp[i][j][len]表示从字符串S中i开始长度为len的字符串是否能变换为从字符串T中j开始长度为len的字符串
        转移方程：
        1)dp[i][j][k]={dp[i][j][w] && dp[i+w][j+w][k-w]},1 <= w <= k-1
        2)dp[i][j][k]={dp[i][j+k-w][w] && dp[i+w][j][k-w]},1<= w <= k-1
        初始化：
        对于长度是1的子串，只有相等才能变过去
        最终答案为dp[0][0][n]
        时间复杂度：O(N^4)
        空间复杂度：O(N^3)
     */
    public boolean isScramble(String s1, String s2) {
        char[] chs1 = s1.toCharArray();
        char[] chs2 = s2.toCharArray();
        int n = s1.length();
        int m = s2.length();
        if(n != m){
            return false;
        }
        boolean[][][] dp = new boolean[n][n][n+1];
        // 初始化：单个字符的判断
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dp[i][j][1] = chs1[i] == chs2[j];
            }
        }

        // 枚举区间长度 2~n
        for(int len = 2; len <= n; len++){
            // 枚举S中的起点位置
            for(int i = 0; i<= n - len; i++){
                // 枚举T中的起点位置
                for(int j = 0; j <= n - len; j++){
                    // 枚举划分位置
                    for(int k = 1; k <= len - 1; k++){
                        // 第1种情况：S1 -> T1，S2 -> T2
                        if(dp[i][j][k] && dp[i+k][j+k][len-k]){
                            dp[i][j][len] = true;
                            break;
                        }
                        // 第2种情况：S1->T2, S2->T1
                        if(dp[i][j+len-k][k] && dp[i+k][j][len-k]){
                            dp[i][j][len] = true;
                            break;
                        }
                    }
                }
            }
        }

        return dp[0][0][n];
    }
}