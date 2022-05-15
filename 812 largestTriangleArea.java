class Solution {
    public double largestTriangleArea(int[][] points) {
        double res = 0;
        // 遍历所有点形成的三角形，暴力求解
        for(int i = 0; i < points.length; i++)
            for(int j = i + 1; j < points.length; j++)
                for(int k = j + 1; k < points.length; k++)
                    res = Math.max(res, 0.5 * Math.abs(points[i][0] * points[j][1] + points[i][1] * points[k][0] + points[j][0] * points[k][1] - points[i][0] * points[k][1] - points[i][1] * points[j][0] - points[j][1] * points[k][0]));
        
        return res;
    }
}