// 1、根据权重数组w生成前缀和数组preSum
// 2、生成一个取值在preSum之内的随机数，用二分搜索算法寻找大雨等于这个随机数的最小元素索引
// 3、最后对这个索引减一（因为前缀和数组有一位索引偏移），就可以作为权重数组的索引，即最终答案
class Solution {
    // 前缀和数组
    private int[] preSum;
    private Random rand = new Random();

    public Solution(int[] w) {
        int n = w.length;
        // 构建前缀和数组，偏移一位留给preSum[0]
        preSum = new int[n+1];
        preSum[0] = 0;
        // preSum[i] = sum(w[0…i-1])
        for(int i = 1; i <= n; i++){
            preSum[i] = preSum[i-1]+w[i-1];
        }
    }
    
    public int pickIndex() {
        int n = preSum.length;
        // 在闭区间[1,preSum[n-1]]中随机选择一个数字
        int target = rand.nextInt(preSum[n-1])+1;
        // 获取target在前缀和数组preSum中的索引
        // 搜索左侧边界的二分搜索
        int left = 0, right = n;
        while(left < right){
            int mid = left + (right - left)/2;
            if(preSum[mid] < target){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        // preSum的索引偏移了一位，还原为权重数组w的索引
        return left - 1;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */