class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int sc=0,l=0,h=tokens.size()-1,ans=0;
        sort(tokens.begin(),tokens.end());
        while(l<=h){
            if(power>=tokens[l]){
                power-=tokens[l];
                sc++;
                l++;
            }
            else{
                if(sc){
                    sc--;
                    power+=tokens[h];
                    h--;
                }
                else
                    break;
            }
            ans=max(ans,sc);
        }
        return ans;
    }
};