class Solution(object):
    # 画图理解两个区间的关系
    # A,B形如[[0,2],[5,10]...]
    def intervalIntersection(self, firstList, secondList):
        """
        :type firstList: List[List[int]]
        :type secondList: List[List[int]]
        :rtype: List[List[int]]
        """
        i,j = 0, 0 # 双指针
        res = []
        while i < len(firstList) and j < len(secondList):
            a1, a2 = firstList[i][0], firstList[i][1]
            b1, b2 = secondList[j][0], secondList[j][1]
            # 两个区间不存在交集就是 a2 < b1 or b2 < a1，取否命题就是存在交集的条件
            # 两个区间存在交集
            if b2 >= a1 and a2 >= b1:
                # 计算出交集，加入res
                res.append([max(a1, b1), min(a2, b2)])
            # 指针前进
            if b2 < a2: j+= 1
            else: i += 1
        return res