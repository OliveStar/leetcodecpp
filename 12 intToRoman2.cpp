class Solution {
public:
    // 算法2：直接枚举个位到千位四位上数字的所有情况
    string intToRoman(int num) {
        vector<string> M{"", "M", "MM", "MMM"};
        vector<string> C{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> X{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> I{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10]; 
    }
};