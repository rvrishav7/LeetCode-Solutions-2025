class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(k==1)
            return true;
        map<int,int>mp;
        for(auto &x:nums)
            mp[x]++;
        bool changed;
        do{
            changed=false;
            if(mp.size()<k)
                return false;
            auto last=mp.begin()->first;
            auto curr=mp.begin();
            curr++;
            int x=k;
            mp[last]--;
            if(!mp[last])
                mp.erase(last);
            while(curr!=mp.end() && --x){
                if(curr->first-last!=1)
                    return false;
                curr->second--;
                last=curr->first;
                curr++;
                if(!mp[last])
                mp.erase(last);
                changed=true;
            }
        }while(changed && mp.size());
        return mp.size()==0;
    }
};