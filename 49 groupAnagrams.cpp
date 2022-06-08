class Solution {
public:
    /**
    ** 算法：构成变位词的字符串中字符种类和个数是一样的，所以每组变位词中的字符串排序后是相同的。
    ** 遍历原始字符串数组，给每个字符串排序，然后判断排序后的字符串是否在Hash Table中存在
    ** 每组变位词字符串在Hash Table中对应的键值一样，是单个字符串排序后的新字符串
    ** 如果存在将原字符串加入存储该组变位词的数组中
    ** 如果不存在为该组变位词新建数组存储
    ** 最后对每组变位词对应的字符串数组排序。因为题目要求字典序。
    **/
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> hash;
        vector<vector<string>> ret;
        int idx = 0;
        for(auto str : strs){
            string s = str;
            sort(s.begin(), s.end());
            if(hash.find(s) != hash.end()){
                ret[hash[s]].push_back(str);
            }
            else{
                hash[s] = idx++;
                ret.push_back(vector<string>(1, str));
            }
        }
        for(int i = 0; i < idx; i++){
            sort(ret[i].begin(), ret[i].end());
        }
        return ret;
    }
};