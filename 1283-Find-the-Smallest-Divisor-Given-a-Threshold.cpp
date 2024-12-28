class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        // TC - O(N^2)
        // for (double i = 1; i < INT_MAX; i++) {
        //     int sum = 0;
        //     for (int j = 0; j < nums.size(); j++) {
        //         double k = ceil(nums[j] / i);
        //         sum +=k;
        //     }
        //     if (sum <= threshold)
        //         return i;
        // }
        // return 0;
        int low = 0 , high = 1e6 , ans = 0;
        while(low <= high){
            double mid = low + (high - low) / 2;
            double sum = 0;
            for(int i = 0; i < nums.size(); i++){
                sum += ceil(nums[i] / mid);
                if(sum > threshold){
                    break;
                }
            }
            if(sum <= threshold){
                high = mid - 1;
                ans = mid;
            }
            else low = mid + 1;
        }
        return ans;
    }
};

// Side Note -->
// the ans will always be in between 1 and the max_ele in arr...
// as after dividing it by greater than it , the sum will be always be equal to sizeof(arr), so if sizeof(arr) > threshold then no answer would be possible.