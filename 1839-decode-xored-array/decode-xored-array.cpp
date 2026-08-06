class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int>ans;
        ans.push_back(first);
        int val=first;;
        for(auto &x:encoded){
            val=x^val;
            ans.push_back(val);
        }
        return ans;
    }
};