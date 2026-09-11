class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(),time.end());

        long long ans=LLONG_MAX,l=1,h=(long long )time[0]*(long long )totalTrips,mid,temp;
        while(l<=h){
            mid=(l+h)/2;
            temp=0;
            for(auto &x: time){
                temp+=(mid/x);
            }
            if(temp>=totalTrips)
            {    h=mid-1;
                 ans=min(ans,mid);
            }
            else
                l=mid+1;
        }
        return ans;
    }
};