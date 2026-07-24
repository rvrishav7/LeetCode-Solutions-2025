class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,bool>mp;
        for(auto &x: arr){
            if(mp.find(2*x)!=mp.end()){
                return true;
            }
            if(x%2==0 && mp.find(x/2)!=mp.end())
                return true;
            mp[x]=true;
        }
        return false;
    }
};