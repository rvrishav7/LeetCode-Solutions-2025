
class Solution {
public:
int parent[100001],rank1[100001];
static bool cmp(vector<int>&a, vector<int>&b){
    return a[2]<b[2];     
}

int find_parent(int p){
    if(p==parent[p])
        return p;
    return parent[p]=find_parent(parent[p]);
}
void union_parent(int &a, int &b){
    int parent_a=find_parent(a);
    int parent_b=find_parent(b);
    if(rank1[parent_a]<rank1[parent_b]){
        parent[parent_a]=parent_b;
        rank1[parent_b]++;
    }
    else{
        parent[parent_b]=parent_a;
        rank1[parent_a]++;
    }
}
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        int q=queries.size(),max_limit,j=0,u,v,idx;
        vector<bool>ans(q);
        for(int i=0;i<n;i++){
            parent[i]=i;
            rank1[i]=1;
        }
        for(int i=0;i<q;i++)
            queries[i].push_back(i);
        sort(edgeList.begin(),edgeList.end(),cmp);  //sort
        sort(queries.begin(),queries.end(),cmp);     //sort

        for(int i=0;i<q;i++){
            max_limit=queries[i][2];        // max limit edge allowed for this query i 
            idx=queries[i][3];
            while(j<edgeList.size()&&edgeList[j][2]<max_limit){    // add {u,v} to the disjoint set
                union_parent(edgeList[j][0],edgeList[j][1]);
                j++;
            }
            ans[idx]=(find_parent(queries[i][0])==find_parent(queries[i][1]));
        }
        return ans;
    }
};