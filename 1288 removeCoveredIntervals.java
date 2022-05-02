class Solution {
    public int removeCoveredIntervals(int[][] intervals) {
        // 按照起点升序排列，起点相同时按终点降序排列
        // 终点如果按升序排列，覆盖区间会被误判成相交区间。所以只能按终点降序排列。
        Arrays.sort(intervals, (a,b) -> {
            if(a[0] == b[0]){
                return b[1] - a[1];
            }
            return a[0] - b[0];
        });

        // 记录合并区间的起点和终点
        int left = intervals[0][0];
        int right = intervals[0][1];

        int res = 0;
        for(int i = 1; i < intervals.length; i++){
            int[] intv = intervals[i];
            // case1: 找到了覆盖区间
            if(left <= intv[0] && right >= intv[1]){
                res++;
            }
            // case2: 找到相交区间，合并
            if(right >= intv[0] && right <= intv[1]){
                right = intv[1];
            }
            // case3: 完全不相交，更新起点和终点
            if(right < intv[0]){
                left = intv[0];
                right = intv[1];
            }
        }
        // 计算出被覆盖的区间数，用总数相减就是剩余区间数
        return intervals.length - res;
    }
}