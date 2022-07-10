class Solution {
    // 算法：单调栈，利用84题的解法
    // 时间复杂度：O(mn)
    // 空间复杂度：O(n)
    public int maximalRectangle(char[][] matrix) {
        if(matrix.length == 0){
            return 0;
        }
        int[] heights = new int[matrix[0].length];
        int maxArea = 0;
        for(int row = 0; row < matrix.length; row++){
            // 遍历每一列，更新高度
            for(int col = 0; col < matrix[0].length; col++){
                if(matrix[row][col] == '1'){
                    heights[col] += 1;
                }else{
                    heights[col] = 0;
                }
            }
            // 调用上一题的解法，更新函数
            maxArea = Math.max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }

    public int largestRectangleArea(int[] heights){
        int maxArea = 0;
        Stack<Integer> stack = new Stack<>();
        int p = 0;
        while(p < heights.length){
            // 栈空入栈
            if(stack.isEmpty()){
                stack.push(p);
                p++;
            }else{
                int top = stack.peek();
                // 当前高度大于栈顶，入栈
                if(heights[p] >= heights[top]){
                    stack.push(p);
                    p++;
                }else{
                    // 保存栈顶高度
                    int height = heights[stack.pop()];
                    // 左边第一个小于当前柱子的下标
                    int leftLessMin = stack.isEmpty() ? -1 : stack.peek();
                    // 右边第一个小雨当前柱子的下标
                    int RightLessMin = p;
                    // 计算面积
                    int area = (RightLessMin - leftLessMin - 1) * height;
                    maxArea = Math.max(area, maxArea);
                }
            }
        }
        while(!stack.isEmpty()){
            // 保存栈顶高度
            int height = heights[stack.pop()];
            // 左边第一个小于当前柱子的下标
            int leftLessMin = stack.isEmpty() ? -1 : stack.peek();
            // 右边没有小于当前高度的柱子，所以赋值为数组的长度便于计算
            int RightLessMin = heights.length;
            int area = (RightLessMin - leftLessMin - 1) * height;
            maxArea = Math.max(area, maxArea);
        }
        return maxArea;
    }
}