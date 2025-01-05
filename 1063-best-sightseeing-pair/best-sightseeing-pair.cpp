class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n= values.size(),maxi=values[n-1],ans=0;
        vector<int>postMax(n);
        postMax[n-1]=INT_MIN;
        for(int i=n-2;i>=0;i--)
            postMax[i]=max(postMax[i+1],values[i+1]-(i+1)); // stores max value in range [i+1,n-1]
        for(int i=0;i<n-1;i++)
            ans=max(ans,(i+values[i])+(postMax[i]));
        return ans;
    }
};