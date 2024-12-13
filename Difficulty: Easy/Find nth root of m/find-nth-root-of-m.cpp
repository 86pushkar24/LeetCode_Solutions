//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here.
        if(n == 1) return m;
        
        int l = 1 , h = m;
        while(l <= h){
            int md = l + (h - l) / 2;
            long long v = 1;
            for(int i = 0; i < n; i++){
                v = v * md * 1LL;
            }
            if(m == v)return md;
            else if(v > m)h = md - 1;
            else l = md + 1;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        Solution ob;
        int ans = ob.nthRoot(n, m);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends