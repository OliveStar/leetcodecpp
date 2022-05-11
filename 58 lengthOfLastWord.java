class Solution {
    public int lengthOfLastWord(String s) {
        int len = 0;
        boolean isWord = false;
        for(int i = s.length() - 1; i >= 0; i--){
            if(s.charAt(i) == ' '){
                if(isWord)
                    return len;
            }
            else{
                len++;
                isWord = true;
            }
        }
        return len;
    }
}