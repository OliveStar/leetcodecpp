class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        // state 2^k k=target.size()
        // f[state] 完成state的状态，需要的最少贴纸树木
        // f[state] -> f'[state'] (state, stickers[n+1]) --> state'
        int n = stickers.size();
        int len = target.size();
        int state_num = (1 << len);
        vector<int> states(state_num, len+1);
        states[state_num-1] = 0;

        for(int i = 0; i < n; i++){
            for(int state = state_num - 1; state > 0; state--){
                // state stickers[i] -> state'
                if(states[state] <= len){
                    int new_state = getNewState(target, state, stickers[i]);
                    states[new_state] = std::min(states[new_state], states[state]+1);
                }
            }
        }
        if(states[0] > len){
            return -1;
        }
        return states[0];
    }

private:
    int getNewState(const string& target, const int& state, const string& mask){
        vector<int> nums(26, 0);
        for(int i = 0; i < mask.size();i++){
            nums[mask[i] - 'a']++;
        }
        int new_state = state;
        unsigned int cur = 1;
        for(int i = 0; i < target.size(); i++, cur <<= 1){
            if((state&cur) && nums[target[i] - 'a']>0){
                new_state = new_state - cur;
                nums[target[i] - 'a']--;
            }
        }
        return new_state;
    }
};