class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n(nums.size()),e1(-1),e2(-1),c1(0),c2(0);
        for(int e : nums){
            if(c1 == 0 && e != e2){
                e1 = e;
                c1++;
            }
            else if(c2 == 0 && e != e1){
                e2 = e;
                c2++;
            }
            else if(e == e1){
                c1++;
            }
            else if(e == e2){
                c2++;
            }
            else{
                c1--;
                c2--;
            }
        }
        vector<int> res;
        c1=(0),c2=(0);
        for(int e : nums){
            if(e == e1)c1++;
            if(e == e2)c2++;
        }
        if(e1 == e2) return {e1};
        if(c1 > n/3)res.push_back(e1);
        if(c2 > n/3)res.push_back(e2);
        return res;
    }   
};