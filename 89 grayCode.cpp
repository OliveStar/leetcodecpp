class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        int cnt = pow(2, n);
        for(int i = 0; i < cnt; i++)
            ret.push_back(i ^ (i >> 1));
        return ret;
    }
};