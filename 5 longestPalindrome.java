// 5.最长回文子串
// 算法：双指针
// 寻找回文串的问题核心思想是：从中间开始向两边扩散来判断回文串
// 但回文串长度可能是奇数或偶数，所以需要分类处理，以s[i]为中心扩散或以s[i]和s[i+1]为中心扩散
class Solution {
    public String longestPalindrome(String s) {
        String res = "";
        for(int i = 0; i < s.length(); i++){
            // 以s[i]为中心的最长回文子串
            String s1 = palindrome(s,i,i);
            // 以s[i]和s[i+1]为中心的最长回文子串
            String s2 = palindrome(s,i,i+1);
            // res = longest(res,s1,s2)
            res = res.length() > s1.length()? res : s1;
            res = res.length() > s2.length()? res : s2;
        }
        return res;
    }

    String palindrome(String s, int l, int r){
        // 防止索引越界
        while(l >= 0 && r < s.length() && s.charAt(l) == s.charAt(r)){
            // 向两边展开
            l--;
            r++;
        }
        // 返回以s[l]和s[r]为中心的最长回文串
        // str.substring(int beginIndex，int endIndex);中最终得到的值:beginIndex =< str的值 < endIndex
        return s.substring(l+1, r);
    }
}