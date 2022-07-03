class Solution {
public:
    /**
        算法：单调栈
        宽度是由下标决定的，记录了下标，对应的高度可以直接从输入数组中得出
        只要是遇到了当前柱形的高度比它上一个柱形的高度严格小的时候，一定可以确定它之前的某些柱形的最大高度，并且确定的柱形宽度的顺序是从右边向左边
        在遍历的时候需要记录的信息就是遍历到的柱形的下标，它一左一右的两个柱形的下标的差就是这个面积最大的矩形对应的最大宽度
        在确定一个柱形的面积的时候，除了右边要比当前严格小，左边也要比当前高度严格小。
        时间复杂度：O(N)， 输入数组里的每个元素入栈一次，出栈一次
        空间复杂度：O(N)， 栈的空间最多为N
    **/
    int largestRectangleArea(vector<int>& heights) {
        unsigned long size = heights.size();
        if(size == 1){
            return heights[0];
        }
        int res = 0;
        stack<int> stk;
        for(int i = 0; i < size; i++){
            while(!stk.empty() && heights[stk.top()] > heights[i]){
                int length = heights[stk.top()];
                stk.pop();
                int weight = i;
                // 特殊情况1:弹栈的时候，栈为空
                if(!stk.empty()){
                    weight = i - stk.top() - 1;
                }
                res = max(res, weight * length);
            }
            stk.push(i);
        }
        // 特殊情况2：遍历完成以后，栈中还有元素
        while(!stk.empty()){
            int length = heights[stk.top()];
            stk.pop();
            int weight = size;
            if(!stk.empty()){
                weight = size - stk.top() - 1;
            }
            res = max(res, length * weight);
        }
        return res;
    }
};