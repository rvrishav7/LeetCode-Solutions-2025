class Solution {
public:
    void fun(string &s,vector<string>&ans, int n, bool last){
        if(!n){
            ans.push_back(s);
            return;
        }
        s.push_back('1');
        fun(s,ans,n-1,1);
        s.pop_back();
        if(last){
           s.push_back('0');
            fun(s,ans,n-1,0); 
            s.pop_back();
        }
        
    }
    vector<string> validStrings(int &n) {
        vector<string>ans;
        string s;
        s.push_back('0');
        fun(s,ans,n-1,0);
        s.pop_back();

        s.push_back('1');
        fun(s,ans,n-1,1);
        s.pop_back();
        
        return ans;
    }
};