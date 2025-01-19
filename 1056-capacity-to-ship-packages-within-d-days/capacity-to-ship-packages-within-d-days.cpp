class Solution {
public:
    inline int findDays(vector<int>& weights, int weight){
        int c=1,sum=0;
        for(int i=0;i<weights.size();i++){
            if(weights[i]>weight)
                return INT_MAX;
            sum+=weights[i];
            if(sum<=weight)
                continue;
            sum=weights[i];
            c++;

        }
        return c;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int minWeight=INT_MAX,maxWeight=0,ans=INT_MAX,mid,temp;
        for(int i=0;i<weights.size();i++){
            maxWeight+=weights[i];
            minWeight=min(minWeight,weights[i]);
        }
        while(minWeight<=maxWeight){
            if(maxWeight-minWeight==1){
                temp=findDays(weights,minWeight);
                if(temp<=days)
                    ans=min(ans,minWeight);
                temp=findDays(weights,maxWeight);
                if(temp<=days)
                    ans=min(ans,maxWeight);
                break;
            }
            mid=(minWeight+maxWeight)/2;
            temp=findDays(weights,mid);

            if(temp>days){
                minWeight=mid;
                continue;
            }

            ans=min(ans,mid);
            if(temp<=days)
                maxWeight=mid;
            else
                minWeight=mid;
            
        }
        return ans;
    }
};