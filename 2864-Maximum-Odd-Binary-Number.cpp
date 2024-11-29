class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt_1 = 0 , cnt_0 = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1'){
                cnt_1++;
            }
            else{
                cnt_0++;
            }
        }
        string ans = "";
        for(int i = 0; i < cnt_1 - 1;i++){
            ans += '1';
        }
        for(int i = 0; i < cnt_0;i++){
            ans += '0';
        }
        ans += '1';
        return ans;
    }
};