class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> temp;
        for(int i = 0; i < cards.size(); i++){
            temp.push_back(1.0 * cards[i]);
        }
        return solve(temp);
    }
private:
    double eps = 1e-6;
    bool solve(vector<double> &cards){
        if(cards.size() == 1){
            if(abs(cards[0] - 24.0) <= eps){
                return true;
            }
        }
        for(int i = 0; i < cards.size();i++){
            for(int j = i + 1; j < cards.size(); j++){
                vector<double> temp;
                for(int k = 0; k < cards.size(); k++){
                    if(k != i && k != j){
                        temp.push_back(cards[k]);
                    }
                }
                double a = cards[i];
                double b = cards[j];
                vector<double> poss;
                poss.push_back(a+b);
                poss.push_back(a*b);
                poss.push_back(a-b);
                poss.push_back(b-a);
                if(abs(b) > 0.0){
                    poss.push_back(a/b);
                }
                if(abs(a) > 0.0){
                    poss.push_back(b/a);
                }
                for(double pt : poss){
                    temp.push_back(pt);
                    if(solve(temp)){
                        return true;
                    }
                    temp.pop_back();
                }
            }
        }
        return false;
    }
};