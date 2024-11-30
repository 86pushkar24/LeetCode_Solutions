//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

 class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int sum = 0; 
        int start = 0;

        // Use a sliding window approach
        for (int end = 0; end < arr.size(); end++) {
            sum += arr[end]; // Add the current element to the sum
            
            // Shrink the window from the left if the sum exceeds the target
            while (sum > target && start <= end) {
                sum -= arr[start];
                start++;
            }

            // If the sum matches the target, return the indices
            if (sum == target) {
                return {start + 1, end + 1}; // Convert to 1-based index
            }
        }

        // If no subarray is found, return {-1}
        return {-1};
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore(); // Ignore the newline character after d

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends