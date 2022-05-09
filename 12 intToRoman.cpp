class Solution {
public:
    string intToRoman(int num) {
        vector<int> int_val{1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> roman_val{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string ret = "";

        for(int i = 0; i < 13; i++){
            while(num >= int_val[i]){
                ret += roman_val[i];
                num -= int_val[i];
            }
        }

        return ret;
    }
};