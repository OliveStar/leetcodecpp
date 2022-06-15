class Solution {
public:
    /**
        算法：动态规划
        在任意位置，机器人有两个选择，向下或向右，把向下和向右两个位置所有可能的路径相加即得到了
        此位置到右下角所有可能的路径数。
    **/
    int uniquePaths(int m, int n) {
        if(m < 1 && n < 1) return 0;
        vector<vector<int>> rst(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) rst[i][n-1] = 1;
        for(int i = 0; i < n; i++) rst[m-1][i] = 1;

        for(int i = m-2; i >= 0; i--){
            for(int j = n-2; j >= 0; j--){
                rst[i][j] = rst[i+1][j] + rst[i][j+1];
            }
        }

        return rst[0][0];
    }
};