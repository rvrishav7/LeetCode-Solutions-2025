class Solution {
public:
    int parser(string &s){
        int cnt=0;
        for(auto &x: s)
            cnt+=(x==' ');
        return cnt+1;
    }
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string,int>ans;
        int maxCnt=0;
        string res;
        for(int i=0;i<messages.size();i++){
            
            ans[senders[i]]+=parser(messages[i]);
            int cnt=ans[senders[i]];
            if(maxCnt<cnt){
                maxCnt=cnt;
                res=senders[i];
            }
            if(maxCnt==cnt)
                res=max(res,senders[i]);

            cout<<senders[i]<< " "<<ans[senders[i]]<<endl;
        }
        return res;
    }
};