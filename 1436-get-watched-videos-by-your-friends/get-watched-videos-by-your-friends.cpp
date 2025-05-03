class Solution {
public:
    void dfs(vector<vector<int>>&gr, vector<bool>&visited, set<int>&kthFriend, int s, int k){
        if(k<0 || visited[s])
            return;
        if(k==0){
            kthFriend.insert(s);
            return;
        }
        visited[s]=true;

        for(auto &x: gr[s])
            dfs(gr,visited,kthFriend,x,k-1);
        visited[s]=false;
    }
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
    int n=friends.size();
    vector<vector<int>>gr(n);
    set<int>kthFriend;
    vector<string>ans;
    set<pair<int,string>>s;
    unordered_map<string,int>mp;
    vector<int>dis(n,1100000000);
    for(int i=0;i<n;i++){
        for(int j=0;j<friends[i].size();j++){
            gr[i].push_back(friends[i][j]);
            gr[friends[i][j]].push_back(i);
        }
    }
   // dfs(gr,visited,kthFriend,id,level); //get friend list at kth level
    queue<pair<int,int>>q;
    q.push({id,0});
    dis[id]=0;
    while(!q.empty()){
        pair<int,int>f=q.front();
        q.pop();
        if(f.second==level){
            kthFriend.insert(f.first);
            continue;
        }
        for(auto &x: gr[f.first])
            if(dis[f.first]+1<dis[x]){
                q.push({x,f.second+1});
                dis[x]=dis[f.first]+1;
            }
    }
    for(auto &x: kthFriend){
        cout<<x<<endl;
        for(auto &video: watchedVideos[x]){
            mp[video]++;
        }
    }
    for(auto &x: mp)
        s.insert({x.second,x.first});
    for(auto &x: s)
        ans.push_back(x.second);
    return ans;
}
};