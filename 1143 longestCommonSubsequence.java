class Solution {
    int[][] memo;
    String t1;
    String t2;
    public int longestCommonSubsequence(String text1, String text2) {
        memo = new int[1000][1000];
        t1=text1;
        t2=text2;
        for(int i=0; i<1000; i++){
            Arrays.fill(memo[i],Integer.MIN_VALUE);
        }
        return dp(t1.length()-1, t2.length()-1);
    }
    int dp(int i, int j){
        // dp(i,j)表示s1(0,…,i)和s2(0,…,j)的最长公共子序列的长度
        // base case：当text1到头时，比较text1第1个字符在text2剩余的子串中有没有相同的字符
        // 如果有，则最长公共子序列就是text1[0]，长度为1，否则没有公共子序列，长度为0.
        if(i == 0){
            for(int tot = 0; tot <= j; tot++){
                if(t1.charAt(i) == t2.charAt(tot)){
                    memo[i][j] = 1;
                    return 1;
                }
            }
            memo[i][j] = 0;
            return 0;
        }
        // base case：当text2到头时，比较text2第1个字符在text1剩余的子串中有没有相同的字符
        if(j == 0){
            for(int tot = 0; tot <= i; tot++){
                if(t2.charAt(j) == t1.charAt(tot)){
                    memo[i][j] = 1;
                    return 1;
                }
            }
            memo[i][j] = 0;
            return 0;
        }
        // 查看备忘录中是否有结果
        if(memo[i][j] != Integer.MIN_VALUE)
            return memo[i][j];
        int res1, res2, res3 = Integer.MIN_VALUE;
        // 如果text1[i] == text2[j]，则这个字符是最长公共子序列中的1个字符
        if(t1.charAt(i) == t2.charAt(j)){
            memo[i][j] = dp(i-1,j-1)+1;
        }else{
            // 如果text1[i] ！= text2[j]，则有两种遍历方式，text1往前走1步 or text2往前走1步
            memo[i][j] = Math.max(dp(i-1,j),dp(i,j-1));
        }
        return memo[i][j];
    }
}