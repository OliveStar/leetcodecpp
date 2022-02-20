class Solution {
public:
    // 如果选择站点 i 作为起点「恰好」无法走到站点 j，那么 i 和 j 中间的任意站点 k 都不可能作为起点。
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += gas[i] - cost[i];
        }
        if(sum < 0){
            // 总油量小于总的消耗，无解
            return -1;
        }
        // 记录油箱中的油量
        int tank = 0;
        // 记录起点
        int start = 0;
        for(int i = 0; i < n; i++){
            tank += gas[i] - cost[i];
            if(tank < 0){
                // 无法从start走到i
                // 所以站点i+1应该是起点
                tank = 0;
                start = i + 1;
            }
        }
        return start;
    }
};