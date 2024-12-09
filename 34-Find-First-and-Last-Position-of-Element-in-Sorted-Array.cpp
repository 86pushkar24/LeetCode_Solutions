// class Solution {
// public:
//     int lowerbound(vector<int> nums, int target, int high, int low) {
//         int ans = nums.size();
//         while (low <= high) {
//             int mid = low + (high - low) / 2;
//             // if (nums[mid] == target)
//             //     return mid;
//             if (nums[mid] >= target) {
//                 ans = mid;
//                 high = mid - 1;
//             } else
//                 low = mid + 1;
//         }
//         return ans;
//     }
//     int upperbound(vector<int> nums, int target, int high, int low) {
//         int ans = nums.size();
//         while (low <= high) {
//             int mid = low + (high - low) / 2;
//             // if (nums[mid] == target)
//             //     return mid;
//             if (nums[mid] > target) {
//                 ans = mid;
//                 high = mid - 1;
//             } else
//                 low = mid + 1;
//         }
//         return ans;
//     }
//     vector<int> searchRange(vector<int>& nums, int target) {
//         if (nums.size() == 0)
//             return {-1, -1};
//         int low = 0, high = nums.size() - 1;
//         int lb = lowerbound(nums, target, high, low);
//         // cout << lb << \ \;
//         // if(lb == nums.size()) lb = -1;
//         if (lb == nums.size() || nums[lb] != target) {
//             lb = -1;
//         }
//         int ub = upperbound(nums, target, high, low) - 1;
//         // cout << ub << \ \;
//         // if(ub == -1) ub = -1;
//         if (ub == -1 || nums[ub] != target)ub = -1;
//         return {lb, ub};
//     }
// };
class Solution {
public:
    int lowerbound(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int ans = nums.size();
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    int upperbound(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int ans = nums.size();
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > target) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};

        int lb = lowerbound(nums, target);
        // Smart Implementations
        if (lb == nums.size() || nums[lb] != target) return {-1, -1};

        int ub = upperbound(nums, target) - 1;
        return {lb, ub};
    }
};