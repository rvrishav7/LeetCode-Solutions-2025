class Solution {
public:
    bool cmp(vector <int> a, vector <int> b)
    {
        return a[1]<b[1];
    }
    int findLongestChain(vector<vector<int>>& ar) {
        int n=ar.size();
        vector <int> res(n,1);
        if(!n)
            return 0;
        int maxi=1;
        sort(ar.begin(),ar.end());
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(ar[j][1]<ar[i][0])
                    res[i]=max(res[i],res[j]+1);
            }
            maxi=max(res[i],maxi);
        }
        return maxi;
    }
};