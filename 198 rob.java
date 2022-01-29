class Solution {
    int[] rooms;
    int[] memo;
    public int rob(int[] nums) {
        rooms = nums;
        memo = new int[rooms.length];
        Arrays.fill(memo, Integer.MIN_VALUE);
        return dp(rooms.length - 1);
    }

    // dp函数定义为从第0个房间到第pos个房间，一共可以偷到的最高金额
    int dp(int pos){
        if(pos < 0) return 0;
        if(memo[pos] != Integer.MIN_VALUE) return memo[pos];
        memo[pos] = Math.max(dp(pos - 1), dp(pos - 2) + rooms[pos]);
        return memo[pos];
    }
}