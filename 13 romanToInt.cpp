class Solution {
    int getVal(char ch){
        switch(ch){
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            default:
                return 1000;
        }
    }
public:
    int romanToInt(string s) {
        int ret = 0;
        for(int i = 0; i < s.size() - 1; i++){
            if(getVal(s[i]) < getVal(s[i+1]))
                ret -= getVal(s[i]);
            else
                ret += getVal(s[i]);
        }
        ret += getVal(s.back());
        return ret;
    }
};