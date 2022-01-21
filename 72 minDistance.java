class Solution {
    // 使用带备忘录的递归自顶向下求解最少操作数
    int[][] memo;
    public int minDistance(String word1, String word2) {
        memo = new int[500][500];
        for(int i = 0; i < word1.length(); i++){
            Arrays.fill(memo[i], Integer.MAX_VALUE);
        }
        return dp(word1.length()-1, word2.length()-1,word1, word2);
    }

    // dp(i, j)表示字符串s1(0…i)到字符串s2(0…j)的最少操作数
    // word1为原始串s1（编辑串），word2为目标串s2
    int dp(int i, int j, String word1, String word2){
        // 原始串遍历完毕，将目标串剩下的所有字符插入到原始串的头部
        if(i == -1) return j+1;
        // 目标串遍历完毕，将原始串头部剩余的字符全部删掉
        if(j == -1) return i+1;
        // 如果备忘录里有已经计算过的结果，直接返回
        if(memo[i][j] != Integer.MAX_VALUE)
            return memo[i][j];
        // s1(i) == s2(j)，这个字符不需要改动，编辑距离等于s(i-1)和s(j-1)的编辑距离
        if(word1.charAt(i) == word2.charAt(j)){
            memo[i][j] = dp(i-1, j-1, word1, word2);
        }else{
            // 对应字符的删，增， 改3个操作
            memo[i][j] = min(dp(i-1,j,word1, word2)+1, dp(i,j-1,word1,word2)+1, dp(i-1, j-1, word1, word2)+1);
        }
        return memo[i][j];
    }

    int min(int a, int b, int c){
        return Math.min(a, Math.min(b, c));
    }
}