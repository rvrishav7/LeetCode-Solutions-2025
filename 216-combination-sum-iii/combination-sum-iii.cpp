class Solution {
public:
    vector<vector<int>>ans;
    void fun(int n, int k, int num,vector<int>&temp){
        if(n==0&&k==0){
            ans.push_back(temp);
            return;
        }
        if(n<=0||k<=0||num<=0)
            return;
        temp.push_back(num);
        fun(n-num,k-1,num-1,temp);
        temp.pop_back();
        fun(n,k,num-1,temp);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        fun(n,k,9,temp);
        return ans;
    }
};