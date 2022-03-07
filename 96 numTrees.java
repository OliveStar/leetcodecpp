class Solution {
    // 备忘录
    int[][] memo;
    public int numTrees(int n) {
        // 备忘录的值初始化为 0
        memo = new int[n+1][n+1];
        // 计算闭区间[1,n]组成的BST个数
        return count(1,n);
    }

    /**计算闭区间[lo,hi]组成的BST个数 */
    int count(int lo, int hi){
        // base case：当lo>hi，闭区间[lo, hi]是个空区间，对应空节点null，也是一种情况，要返回1
        if(lo > hi) return 1;
        
        // 查备忘录
        if(memo[lo][hi] != 0){
            return memo[lo][hi];
        }

        int res = 0;
        for(int mid = lo; mid <= hi; mid++){
            // i的值作为根节点root
            // 根据BST特性，根节点的左子树都比根节点的值小
            // 根节点的右子树都比根节点的值大
            int left = count(lo, mid-1);
            int right = count(mid+1, hi);
            // 左右子树的组合数乘积是BST的总数
            res += left * right;
        }

        // 将结果存入备忘录
        memo[lo][hi] = res;
        
        return res;
    }

}