class Solution {
public:
     map<int,int> mp;
    vector<vector<int>> res;
    void help(int len,int k,vector <int> &temp,map<int,int>:: iterator it){
        if(len==k){
            res.push_back(temp);
            return;
        }
        for(auto i=it;i!=mp.end();i++){
            if(i->second>0){
                i->second--;
                temp.push_back(i->first);
                auto j=i;
                j++;
                help(len+1,k,temp,j);
                i->second++;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        for(int i=1;i<=n;i++)
            mp[i]=1;
        vector <int> temp;
        auto j=mp.begin();
        help(0,k,temp,j);
        return res;
    }
};