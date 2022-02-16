class Solution {
    int intervalSchedule(int[][] intvs){
        if(intvs.length == 0) return 0;
        // 按end升序排序
        Arrays.sort(intvs, new Comparator<int[]>(){
            public int compare(int[] a, int[] b){
                return a[1] - b[1];
            }
        });
        // 至少有一个区间不相交
        int count = 1;
        // 排序后，第一个区间就是x
        int x_end = intvs[0][1];
        for(int[] interval : intvs){
            int start = interval[0];
            if(start >= x_end){
                // 找到下一个选择的区间了
                count++;
                x_end = interval[1];
            }
        }
        return count;
    }
    public int eraseOverlapIntervals(int[][] intervals) {
        int n = intervals.length;
        // 总的区间个数去掉不重叠的区间个数，就是要移除的区间个数
        return n - intervalSchedule(intervals);
    }
}