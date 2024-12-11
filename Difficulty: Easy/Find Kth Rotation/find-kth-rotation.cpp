//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int findKRotation(vector<int> &nums) {
        // Code Here
        int low = 0 , high = nums.size() - 1;
        int mini = INT_MAX;
        int idx = 0;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] >= nums[low]){//  2 1
                if(mini > nums[low]){
                    mini = nums[low];
                    idx = low;  
                }
                // mini = min(mini , nums[low]);
                low = mid + 1;
            }
            else{
                // mini = min(mini , nums[mid]);
                if(mini > nums[mid]){
                    mini = nums[low];
                    idx = mid;  
                }
                // idx = mid;
                high = mid - 1;
            }
        }
        return idx;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        Solution ob;
        int res = ob.findKRotation(arr);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends