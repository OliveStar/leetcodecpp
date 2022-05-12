class Solution {
    // 暴力法：x的平方根在2~x-1之间，搜索区间，逐个试。时间复杂度O(sqrt(x));
    // 二分查找：每次缩小一半的查找区间，时间复杂度O(logN)
    // 牛顿迭代法：令n*n=x，则n就是要求的平方根。寻找x/n和n的均值，比这两个数更趋近于sqrt(x)，递归求解
    int binarysearch(int x){
        if(x <= 0) return 0;
        if(x == 1) return 1;
        int left = 1, right = x/2, mid;
        while(left <= right){
            mid = left + (right - left) / 2;
            if(mid == x/mid) return mid;
            else if(mid < x/mid) left = mid + 1;
            else right = mid - 1;
        }
        return right;
    }

    int newton(int x){
        if(x <= 0) return 0;
        if(x == 1) return 1;
        return (int)mynewton(x, x);
    }

    double mynewton(double n, int x){
        double res = (n + x/n) /2;
        if(res == n)
            return res;
        return mynewton(res, x);
    }

    public int mySqrt(int x) {
        //return binarysearch(x);
        return newton(x);
    }
}