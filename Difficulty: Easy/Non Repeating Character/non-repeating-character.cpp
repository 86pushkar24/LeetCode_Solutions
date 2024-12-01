//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the first non-repeating character in a string.
    char nonRepeatingChar(string &s) {
    unordered_map<char, int> freqCount;
    // First pass: Count the frequency of each character
    for (char ch : s) {
        freqCount[ch]++;
    }
    // Second pass: Find the first character with a frequency of 1
    for (char ch : s) {
        if (freqCount[ch] == 1) {
            return ch;
        }
    }
    return '$'; // Return '$' if no non-repeating character exists
}

};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;

    while (T--) {

        string S;
        cin >> S;
        Solution obj;
        char ans = obj.nonRepeatingChar(S);

        if (ans != '$')
            cout << ans;
        else
            cout << "-1";

        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends