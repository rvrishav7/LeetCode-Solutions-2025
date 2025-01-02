class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size(),maxi=0,temp;
        vector<int>zero(n),one(n);
        zero[0]=(nums[0]==0)?zero[0]+1:zero[0];
        one[n-1]=(nums[n-1]==1)?one[n-1]+1:one[n-1];
        for(int i=1;i<n;i++){
            zero[i]=zero[i-1];
            zero[i]+=(nums[i]==0);
        }

        for(int i=n-2;i>=0;i--){
            one[i]=one[i+1];
            one[i]+=(nums[i]==1);
        }
        for(int i=0;i<n;i++){
            if(i==0)
                temp=one[0];
            else
                temp=zero[i-1]+one[i];
          //  cout<<i<<" "<<temp<<" "<<maxi<<" "<<zero[i]<<" "<<one[i]<<endl;
            if(temp>=maxi){
                if(temp==maxi){
                    ans.push_back(i);
                    continue;
                }
                ans.clear();
                ans.push_back(i);
                maxi=temp;
            }
            
        }
        temp=zero[n-1];
        if(temp>=maxi){
            if(temp==maxi){
                ans.push_back(n);
            }
            else{
                ans.clear();
                ans.push_back(n);
                maxi=temp;
            }
            }
        return ans;
    }
};