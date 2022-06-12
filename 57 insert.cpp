class Solution {
public:
    /**
    ** 算法：画图，分类讨论。
    以测试用例2为例，待查区间[[1,2],[3,5],[6,7],[8,10],[12,16]]和目标区间[4,8]
    1.不重叠的情况，需满足：
    1)查询子区间的右端，位于目标区间的左端的左边，如[1,2]。则当前子区间，推入 res 数组，指针 +1，考察下一个子区间。
    2)循环结束时，当前子区间的右端点，超过了目标区间的左端点，有重叠了，如[3,5]。
    2.有重叠的情况：待查询子区间的左端点 <= 目标区间的右端点，极端的例子就是[8,10]。
    1）和目标区间有重叠的子区间，会合并成一个区间：左端取两个区间左端的较小者，右端取两个区间右端的较大者，不断更新给目标区间。
    2）循环结束时，将目标区间（即合并后的新区间）推入 res 数组。
    3.剩下的，都在目标区间右边，不重叠。不用额外判断，依次推入 res 数组。
    **/
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i = 0;
        int len = intervals.size();
        // 遍历目标区间左侧的不重叠子区间
        while(i < len && intervals[i][1] < newInterval[0]){
            res.push_back(intervals[i]);
            i++;
        }
        // 遍历和目标区间重叠的子区间
        while(i < len && intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }
        res.push_back(newInterval); // 循环后，目标区间更新为合并后的区间，加入res
        // 遍历目标区间右侧的不重叠子区间
        while(i < len){
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    }
};