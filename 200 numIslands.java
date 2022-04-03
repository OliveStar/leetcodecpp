class Solution {
    // DFS：FloodFill算法
    // 把经过的位置都设置为0，也可以做到不走回头路，避免维护visited数组
    // 主函数，计算岛屿数量
    public int numIslands(char[][] grid) {
        int res = 0;
        int m = grid.length, n = grid[0].length;
        // 遍历grid
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    // 每发现一个岛屿，岛屿数量加一
                    res++;
                    // 然后使用DFS将岛屿淹了
                    dfs(grid,i,j);
                }
            }
        }
        return res;
    }

    // 从(i,j)开始，将与之相邻的陆地都变成海水
    void dfs(char[][] grid, int i, int j){
        int m = grid.length, n = grid[0].length;
        if(i < 0 || j < 0 || i >= m || j >= n){
            // 超出索引边界
            return;
        }
        if(grid[i][j] == '0'){
            // 已经是海水了
            return;
        }
        // 将（i,j）变成海水
        grid[i][j] = '0';
        // 淹没上下左右的陆地
        dfs(grid, i+1, j);
        dfs(grid, i, j+1);
        dfs(grid, i-1,j);
        dfs(grid, i, j-1);
    }
}