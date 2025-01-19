class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int curr=0;
        int cap[100001];
        memset(cap,0,sizeof(cap));
        for(int i=0;i<trips.size();i++){
            cap[trips[i][1]]+=trips[i][0];
            cap[trips[i][2]]-=trips[i][0];
        }
        for(int i=0;i<100001;i++){
            curr+=cap[i];
            if(curr>capacity)
                return false;
        }
        return true;
    }
};