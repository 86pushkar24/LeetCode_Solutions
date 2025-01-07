class Solution
{
    public:
        int mini(const vector<int> &bloomDay)
        {
            int ans = INT_MAX;
            for (int i = 0; i < bloomDay.size(); i++)
            {
                ans = min(ans, bloomDay[i]);
            }
            return ans;
        }
    int maxi(const vector<int> &bloomDay)
    {
        int ans = INT_MIN;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            ans = max(ans, bloomDay[i]);
        }
        return ans;
    }
    int cnt(const vector<int> &bloomDay, int mid, int k)
    {
        int count = 0;
        int ans = 0;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            if (bloomDay[i] <= mid)
            {
                count++;
            }
            else
            {
                ans += count / k;
                count = 0;
            }
        }
        ans += count/k;
        return ans;
    }
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        if (1LL* m * k > bloomDay.size())
            return -1;
        int low = mini(bloomDay), high = maxi(bloomDay);
        int ans = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int flowerCount = cnt(bloomDay, mid, k);

            cout << flowerCount << " ";
            if (flowerCount >= m)
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};