class Solution {
public:
    // 算法：从低位进行计算，注意最后的进位就可以了
    string addBinary(string a, string b) {
        int szA = a.size(), szB = b.size();
        if(!szA) return b;
        if(!szB) return a;

        int sz = max(szA, szB);
        int carry = 0, sum;
        string ret = "";
        for(int i = 0; i < sz; i++){
            sum = carry;
            if(i < szA) sum += (a[szA - 1 - i] - '0');
            if(i < szB) sum += (b[szB - 1 - i] - '0');
            carry = sum >> 1;
            ret = char(sum & 0x1 ? '1' : '0') + ret;
        }
        if(carry) ret = char('1') + ret;
        return ret;
    }
};