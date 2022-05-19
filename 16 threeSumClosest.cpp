class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int rst = 0;

        if(nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        rst = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < nums.size() - 2; i++){
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            for(int j = i+1, k = nums.size()-1;j < k;){
                // 需要记录下当前最接近给定值的相加和
                int sum = nums[i] + nums[j] + nums[k];
                // 每次进行判断取最接近的替换记录值
                if(abs(sum - target) < abs(rst - target))
                rst = sum;
                if(sum < target){
                    do{
                        j++;
                    }
                    while(nums[j] == nums[j-1] && j < k);
                }
                else if(sum > target){
                    do{
                        k--;
                    }while(nums[k] == nums[k+1] && j < k);
                }
                else{
                    return target;
                }
            }
        }

        return rst;
    }
};