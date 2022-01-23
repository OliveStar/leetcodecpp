// 14.最长公共前缀
// 算法说明：取数组中字典序最大和最小的两个字符串，它们的最长公共前缀就是所有字符串的最长公共前缀
// 注意处理遍历寻找最长公共前缀时数组越界情况
class Solution {
    public String longestCommonPrefix(String[] strs) {
        Arrays.sort(strs);
        String ss = strs[0];
        String ls = strs[strs.length-1];
        String res = "";
        int pos = 0;
        while(pos < ss.length() && ss.charAt(pos) == ls.charAt(pos)){
            pos++;
        }
        res = ss.substring(0, pos);
        return res;
    }
}