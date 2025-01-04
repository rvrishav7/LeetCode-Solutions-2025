class Solution {
public:
    void insert(string &st, stack<char>&s){
        for(auto &x: st){
            if(x!='#')
                s.push(x);
            else{
                if(!s.empty())
                    s.pop();
            }
        }
    }
    bool backspaceCompare(string s, string t) {
        stack<char>s1,s2;
        insert(s,s1);
        insert(t,s2);
        if(s1.size()!=s2.size())
            return false;
        if(s1.empty()&&s2.empty())
            return true;
        while(s1.size()){
            if(s1.top()!=s2.top())
                return false;
            s1.pop();
            s2.pop();
        }
        return true;
    }
};