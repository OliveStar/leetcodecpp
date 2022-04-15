/*
核心思路：利用双指针-头尾指针循环判断字符是否相同即可~
循环前需要先统一字符大小写，这里介绍统一转为小写字母
全部转为小写字母
判断是否为有效字符即数字和字母字符！
发现一个不等直接返回false！
*/
class Solution {
    public boolean isPalindrome(String s) {
        String t = s.toLowerCase();
        int len = t.length();
        for(int i = 0, j = len - 1; i < j;){
            char ci = t.charAt(i);
            char cj = t.charAt(j);
            if(!(Character.isDigit(ci) || Character.isLowerCase(ci))){
                i++;
                continue;
            }
            if(!(Character.isDigit(cj) || Character.isLowerCase(cj))){
                j--;
                continue;
            }
            if(ci != cj){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
}