class Solution {
    /**
        用动态规划来求解。如果|s1| + |s2| <> |s3|，s3必然不可能由s1和s2交错形成
        我们定义f(i,j) 表示s1的前i个元素和s2的前j个元素是否能交错组成s3的前i+j个元素。如果s1的第 i个元素和s3的第i+j 个元素相等，那么s1的前i个元素和s2的前j个元素是否能交错组成s3的前i+j 个元素取决于s1的前i−1 个元素和s2的前j个元素是否能交错组成s3的前i+j−1 个元素，即此时f(i,j) 取决于f(i−1,j)，在此情况下如果f(i−1,j) 为真，则f(i,j) 也为真。同样的，如果s2的第j个元素和s3的第i+j 个元素相等并且f(i,j−1) 为真，则f(i,j) 也为真。于是我们可以推导出这样的动态规划转移方程
        f(i,j) = [f(i-1, j) and s1(i-1) = s3(p)] or [f(i, j - 1) and s2(j - 1) = s3(p)]
        其中 p = i + j - 1，边界条件为f(0,0) = True
        算法复杂度：O(nm)
     */
    public boolean isInterleave(String s1, String s2, String s3) {
        int n = s1.length(), m = s2.length(), t = s3.length();
        if(n + m != t){
            return false;
        }

        boolean[][] f = new boolean[n + 1][m + 1];

        f[0][0] = true;
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                int p = i + j - 1;
                if(i > 0){
                    f[i][j] = f[i][j] || (f[i - 1][j] && s1.charAt(i - 1) == s3.charAt(p));
                }
                if(j > 0){
                    f[i][j] = f[i][j] || (f[i][j - 1] && s2.charAt(j - 1) == s3.charAt(p));
                }
            }
        }

        return f[n][m];
    }
}