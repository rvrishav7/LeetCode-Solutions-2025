class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int stream=1;
        vector<string>ans;
        for(auto &x: target){
            while(stream<x){
                ans.push_back("Push");
                ans.push_back("Pop");
                stream++;
            }
            ans.push_back("Push");
            stream++;
        }
        return ans;
    }
};