class Solution {
public:
    bool addEdge(set<int>&a,set<int>&b, int &k){
        unordered_map<int,int>mp;
        int count=0;
        for(auto &x: a)
            mp[x]++;
        for(auto &y: b)
            mp[y]--;
        for(auto &x: mp)
            count+=(x.second==0);
        return count>=k;
    }
    
    int find_parent(vector<int>&parent,int p){
        if(parent[p]==p)
            return p;
        return parent[p]=find_parent(parent,parent[p]);
    }
    void union_(vector<int>&parent,int u, int v){
        int p1=find_parent(parent,u);
        int p2=find_parent(parent,v);
        if(p1==p2)
            return;
        if(p1<p2)
            parent[p2]=p1;
        else
            parent[p1]=p2;
    }
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n=properties.size();
        vector<set<int>>s(n);
        set<int>res;
        vector<int>parent(n);
        for(int i=0;i<n;i++)
            for(auto &y: properties[i])
                s[i].insert(y);
        
        for(int i=0;i<n;i++)
            parent[i]=i;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(addEdge(s[i],s[j],k)){
                    union_(parent,i,j);
                }
            }
        }
        for(int i=0;i<n;i++){
            find_parent(parent,i);
            res.insert(parent[i]);
        }
        return res.size();
    }
};