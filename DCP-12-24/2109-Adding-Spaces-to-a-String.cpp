class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;
        int j = 0;
        for(int i = 0;i < s.size();){
            if(j < spaces.size() && i == spaces[j]){
                ans += " ";
                j++;
            }
            else{
                ans += s[i];
                i++;
            }
        }
        return ans;
    }
};