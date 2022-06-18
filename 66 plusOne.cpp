class Solution {
public:
    // 注意进位的处理以及最终结果位数可能比原数字位数多1
    vector<int> plusOne(vector<int>& digits) {
        vector<int> sum(digits.size()+1, 0);
        int carry = 1;
        for(int i = digits.size()-1; i >= 0; i--){
            sum[i+1] = (digits[i] + carry) % 10;
            carry = (digits[i] + carry) / 10;
        }
        sum[0] = carry;
        if(sum[0]) return sum;
        else
            return vector<int>(sum.begin()+1, sum.end());
    }
};