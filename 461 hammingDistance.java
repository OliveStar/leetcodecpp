class Solution {
    // x和y异或，二进制位上不同数字的被置为1，然后通过n&(n-1)统计1的个数
    public int hammingDistance(int x, int y) {
        int distance = 0;
        for(int i = x ^ y;i != 0; i = i&(i-1)){
            distance++;
        }
        return distance;
    }
}