class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int cnt=0,n=arr.size();
        vector<int> sum(1001,0);
        for(int j = 0; j < n; j++){
            for(int k = j+1; k <n;k++){
                if(abs(arr[j]-arr[k])<=b){
                    int l=max(0,max(arr[j]-a,arr[k]-c));
                    int r=min(1000,min(arr[j]+a,arr[k]+c));
                    if(l<=r){
                        if(l==0){
                            cnt+=sum[r];
                        }
                        else{
                            cnt+=sum[r]-sum[l-1];
                        }
                    }
                }
            }
            for(int i = arr[j]; i <= 1000; i++){
                sum[i]++;
            }
        }
        return cnt;
    }
};