class Solution {
public:
    int countAsterisks(string s) {
        int ans=0;
        bool cnt=false;
        for(auto &x: s){
            if(x=='|')
                cnt=!cnt;
            else if(!cnt && x=='*')
            {
                ans++;
            }
        }
        return ans;
    }
};