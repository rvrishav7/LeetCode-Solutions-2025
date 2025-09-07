class Solution {
public:
    unordered_map<string,bool>mp,visited;
    void inline add_queue(queue<pair<string,int>>&q, string &curr, int &d){
        int digit,plusOne,minusOne;
        string temp=curr;
        for(int i=0;i<4;i++){
            digit=curr[i]-'0';
            plusOne=(digit+1)%10;
            minusOne=(digit-1+10)%10;
            temp=curr;
            temp[i]=plusOne+'0';
            if(!mp[temp]&&!visited[temp])
                q.push({temp,d+1});

            temp=curr;
            temp[i]=minusOne+'0';
            if(!mp[temp]&&!visited[temp])
                q.push({temp,d+1});
        }
    }
    int openLock(vector<string>& deadends, string target) {
        int dis,ans=INT_MAX;
        mp.clear();
        visited.clear();
        for(auto &x: deadends)
            mp[x]=true;
        string curr="0000";
        if(mp[curr])
            return -1;
        queue<pair<string,int>>q;
        q.push({curr,0});

        while(!q.empty()){
            curr=q.front().first;
            int dis=q.front().second;
            q.pop();
            if(curr==target)
                ans=min(ans,dis);
            if(visited[curr])
                continue;
            visited[curr]=true;
            add_queue(q,curr,dis);
        }

        return ans==INT_MAX?-1:ans;
    }
};