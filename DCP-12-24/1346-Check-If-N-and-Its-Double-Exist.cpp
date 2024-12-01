class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        // for(int i = 0; i < arr.size(); i++){
        //     for(int j = 0; j < arr.size();j++){
        //         if(i != j){                     // in case of 0
        //             if(arr[i] == 2 * arr[j]){
        //             return true;
        //             }
        //         }
        //     }
        // }
        map<int , int> mp;
        for(int num : arr){
            mp[num]++;
        }
        for(int num : arr){
            if(mp.find(2*num) != mp.end() && num!=0){
                return true;
            }
            if(num == 0 && mp[num] > 1) return true;
        }
        return false;
    }
};


// a set , map , binary search could also be used for further optimizations
// o(n) o(n) o(nlogn) -- TC
// o(n) o(n) o(logn) -- SC