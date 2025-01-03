class Solution {
public:
    bool check(map<int,int>&mp){
        for(auto &x: mp){
            if(!x.second)
                continue;
            while(x.second){
                if(mp[2*x.first]<=0)
                    return false;
                x.second--;
                mp[2*x.first]--;
            }
            if(x.second>0)
                return false;
        }
        return true;
    }
    bool canReorderDoubled(vector<int>& arr) {
        map<int,int>pos,neg;
        for(auto &x: arr){
            if(x>=0)
                pos[x]++;
            else
                neg[-1*x]++;
        }
        return check(neg)&&check(pos);    
    }
};