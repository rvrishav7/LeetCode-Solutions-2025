class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int temp=k;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        vector<int>ans;
        for(auto &x: nums)
            mp[x]++;
        auto p=mp.begin();
        while(temp--&&p!=mp.end()){
            q.push({p->second,p->first});
            p++;
        }
        while(p!=mp.end()){
            q.push({p->second,p->first});
            p++;
            if(q.size()>k)
                q.pop();
        }
        while(!q.empty()){
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};