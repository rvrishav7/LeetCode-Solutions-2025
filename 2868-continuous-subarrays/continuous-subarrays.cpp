class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans=0,start=0;
        deque<int>maxi,mini;
        for(int i=0;i<nums.size();i++){
            while(!maxi.empty()&& nums[maxi.back()]<nums[i])
                maxi.pop_back();
            while(!mini.empty() && nums[mini.back()]>nums[i])
                mini.pop_back();
            maxi.push_back(i);
            mini.push_back(i);
        //    cout<<nums[i]<<": xxxx  "<<start<<" maxi size= "<<maxi.size()<<" mini size= "<<mini.size()<<endl;
            while(abs(nums[mini.front()]-nums[maxi.front()])>2){
                if(mini.front()<maxi.front())
                    mini.pop_front();
                else
                    maxi.pop_front();
            }
            int p=start;
            while(p<min(mini.front(),maxi.front())){
                if(nums[p]>nums[maxi.front()]||nums[p]<nums[mini.front()])
                    start=p+1;
                p++;
            }
           // start=min(mini.front(),maxi.front());
            ans+=(i-start+1);
           // cout<<nums[i]<<":  "<<start<<" maxi = "<<maxi.front()<<" mini = "<<mini.front()<<" ans= "<<ans<<endl;
           // cout<<nums[i]<<":  "<<start<<" maxi size= "<<maxi.size()<<" mini size= "<<mini.size()<<endl;
        }
        return ans;
    }
};