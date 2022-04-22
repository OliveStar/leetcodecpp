class Solution {
    // trips[i]代表一组区间操作，旅客上车和下车相当于数组的区间加减
    // 只要结果数组中的元素都小雨capacity，就说明可以不超载运输所有旅客
    public boolean carPooling(int[][] trips, int capacity) {
        // 最多有1000个车站
        int[] nums = new int[1001];
        // 构造差分解法
        Difference df = new Difference(nums);

        for(int[] trip : trips){
            // 乘客数量
            int val = trip[0];
            // 第trip[1]站乘客上车
            int i = trip[1];
            // 第trip[2]站乘客下车
            // 即乘客在车上的区间是[trip[1], trip[2]-1]
            int j = trip[2] - 1;
            // 进行区间操作
            df.increment(i,j,val);
        }

        int[] res = df.result();

        // 客车自始至终都不应该超载
        for(int i = 0; i < res.length; i++){
            if(capacity < res[i]){
                return false;
            }
        }

        return true;
    }
}

// 差分数组工具类
class Difference{
    // 差分数组
    private int[] diff;

    /** 输入一个初始数组，区间操作将在这个数组上进行 */
    public Difference(int[] nums){
        assert nums.length > 0;
        diff = new int[nums.length];
        // 根据初始数组构造差分数组
        diff[0] = nums[0];
        for(int i = 1; i < nums.length;i++){
            diff[i] = nums[i] - nums[i-1];
        }
    }

    /** 给闭区间[i,j]增加val(可以是负数) */
    public void increment(int i, int j, int val){
        diff[i] += val;
        if(j + 1 < diff.length){
            diff[j+1] -= val;
        }
    }

    /** 返回结果数组 */
    public int[] result(){
        int[] res = new int[diff.length];
        // 根据差分数组构造结构数组
        res[0] = diff[0];
        for(int i = 1; i < diff.length; i++){
            res[i] = res[i-1] + diff[i];
        }
        return res;
    }
}