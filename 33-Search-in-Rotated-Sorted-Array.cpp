// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int low = 0, high = nums.size()-1;
//         while (low <= high) {
//             int mid = low + (high - low) / 2;
//             if (nums[mid] == target) {
//                 return mid;
//             } else if (nums[mid] >= nums[low]) {
//                 if (target >= nums[low] && target < nums[mid]) {
//                     high = mid - 1;
//                 } else {
//                     low = mid + 1;
//                 }
//             } else {
//                 if (target > nums[mid] && target <= nums[high]) {
//                     low = mid + 1;
//                 } else {
//                     high = mid - 1;
//                 }
//             }
//         }
//         return -1;
//     }
// };
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // If the target is found
            if (nums[mid] == target)
                return mid;

            // Left side is sorted
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1; // Target is in the left sorted half
                } else {
                    low = mid + 1; // Target is in the right half
                }
            }
            // Right side is sorted
            else {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1; // Target is in the right sorted half
                } else {
                    high = mid - 1; // Target is in the left half
                }
            }
        }

        return -1; // Target not found
    }
};