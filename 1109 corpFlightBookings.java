class Solution {
    public int[] corpFlightBookings(int[][] bookings, int n) {
        // nums 初始化为全0
        int[] nums = new int[n];
        // 构造差分解法
        Difference df = new Difference(nums);

        for(int[] booking : bookings){
            // 注意转成数组索引要减一
            int i = booking[0] - 1;
            int j = booking[1] - 1;
            int val = booking[2];
            // 对区间 nums[i…j] 增加val
            df.increment(i,j,val);
        }

        // 返回最终的结果数组
        return df.result();
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