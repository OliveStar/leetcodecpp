class Solution {
    int[][] memo;
    String w1;
    String w2;
    public int minimumDeleteSum(String word1, String word2) {
        memo = new int[word1.length()][word2.length()];
        for(int i=0; i < word1.length(); i++){
            Arrays.fill(memo[i], Integer.MAX_VALUE);
        }
        w1 = word1;
        w2 = word2;
        return dp(w1.length()-1, w2.length()-1);
    }

    int dp(int i,int j){
        // base case：s1或s2有1个先遍历结束时，直接把剩下的一个串全删了
        // i,j是下标，实际删除的是长度，比下标多1
        if(i == -1){
            int res = 0;
            for(int tot=0; tot <= j; tot++){
                res  = res + w2.charAt(tot);
            }
            return res;
        }
        if(j == -1){
            int res = 0;
            for(int tot=0; tot <= i; tot++){
                res  = res + w1.charAt(tot);
            }
            return res;
        }
        if(memo[i][j] != Integer.MAX_VALUE)
            return memo[i][j];
        char c1 = w1.charAt(i);
        char c2 = w2.charAt(j);
        if(c1 == c2){
            memo[i][j] = dp(i-1, j-1); // 如果当前遍历的两个字符相等，不需要删除，继续往前搜索
        }else{
            memo[i][j] = Math.min(dp(i-1,j)+c1, dp(i,j-1)+c2); // 当前遍历的两个字符不相等，i或j各往前搜索1步，选择最小的
        }
        return memo[i][j];
    }
}