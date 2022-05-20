class Solution {
public:
    // 算法：区间搜索
    // 以a1和an组成的容器作为初始容器，容器容积为min(a1, an)*(n-1)，把(n-1)记为长，min(a1, an)记为高
    // 计算容器容积时要考虑到长的因素，以min(a1, an)为高的其他任何容器都不会比初始值大
    // 因为其他容器高最大为min(a1, an)，而长必定小于(n-1)，所以a1和an中小的那条线在后续比较重就可以不考虑了
    // 如果min(a1, an) == a1, 我们继续查看a2和an组成的容器，否则查看a1和an-1组成的容器，同时更新最大容器值。依照这样的策略逐步缩小范围，最终就得到了最大容器
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int maxWater = 0;
        while(l < r){
            maxWater = max(maxWater, min(height[r], height[l])*(r-l));
            if(height[l] < height[r]) ++l;
            else --r;
        }
        return maxWater;
    }
};