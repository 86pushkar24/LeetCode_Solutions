class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        // int res = (1<<20) - 1;
        int res = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            if(i == nums[i])continue;
            res = res & nums[i];
        }
        return (res == INT_MAX) ? 0 : res;
    }
};