class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(),piles.end());
        int ans = high;
        while(low <= high){
            int mid = low + (high - low) / 2;
            int sum = 0;
            for(int i = 0; i < piles.size(); i++){
                sum += ceil((double)piles[i] /(double)mid);
                if(sum > h) break;
            }
            cout << sum << " " << mid;
            cout << endl;
            if(sum <= h){
                high = mid - 1;
                ans = mid;
            }
            else low = mid + 1;
        }
        return ans;
    }
};