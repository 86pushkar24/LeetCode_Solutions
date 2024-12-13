class Solution {
public:
    int mySqrt(int n) {
        if (n == 0 || n == 1) return n;  // Handle edge cases
        
        int low = 1, high = n;
        int ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long chk = 1LL * mid * mid; // Use long long to prevent overflow
            
            if (chk == n) {
                return mid;
            } else if (chk > n) {
                high = mid - 1;
            } else {
                ans = mid;
                low = mid + 1;
            }
        }
        return ans;
    }
};