// HashSet插入，删除，查找这3个操作的时间复杂度为O(1)，但getRandom的时间复杂度不为O(1)
// 数组getRandom、查找的时间复杂度是O(1)，但插入、删除的时间复杂度不是O(1)，除非在数组尾部操作
// 因此本题使用的数据结构为HashSet+数组
class RandomizedSet {
    public:
    // 存储元素的值
    vector<int> nums;
    // 记录每个元素对应在nums中的索引
    unordered_map<int, int> valToIndex;

    RandomizedSet() {
         
    }
    
    bool insert(int val) {
        // 若val已存在，不用再插入
        if(valToIndex.count(val)){
            return false;
        }
        // 若val不存在，插入到nums尾部，
        // 并记录val对应的索引值
        valToIndex[val] = nums.size();
        nums.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        // 若val不存在，不用再删除
        if(!valToIndex.count(val)){
            return false;
        }
        // 先拿到val的索引
        int index = valToIndex[val];
        // 将最后一个元素对应的索引修改为index
        valToIndex[nums.back()] = index;
        // 交换val和最后一个元素
        swap(nums[index], nums.back());
        // 在数组中删除元素val
        nums.pop_back();
        // 删除元素val对应的索引
        valToIndex.erase(val);
        return true;
    }
    
    int getRandom() {
        // 随机获取nums中的一个元素
        return nums[rand()%nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */