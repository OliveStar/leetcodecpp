class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[List[int]]
        """
        if not intervals: return[]
        # 按区间的 start 升序排列
        intervals.sort(key=lambda intv : intv[0])
        res = []
        res.append(intervals[0])

        for i in range(1, len(intervals)):
            curr = intervals[i]
            # res中最后一个元素的引用
            last = res[-1]
            if curr[0] <= last[1]:
                # 找到最大的end
                last[1] = max(last[1], curr[1])
            else:
                # 处理下一个待合并区间
                res.append(curr)
        return res