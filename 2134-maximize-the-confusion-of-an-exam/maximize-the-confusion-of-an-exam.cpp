class Solution {
public:
    int maxConsecutiveAnswers(string &answerKey, int &k) {
      // Two pass solution
      int n=answerKey.size(),cnt=0,j=0,ans=0;
      //substring of 'T'
      for(int i=0;i<n;i++){
        if(answerKey[i]=='F')
            cnt++;
        while(cnt>k&&j<=i){
            if(answerKey[j]=='F')
                cnt--;
            j++;
        }
        ans=max(ans,i-j+1);
      } 
    j=0;
    cnt=0;
    // String made of 'F'
      for(int i=0;i<n;i++){
        if(answerKey[i]=='T')
            cnt++;
        while(cnt>k&&j<=i){
            if(answerKey[j]=='T')
                cnt--;
            j++;
        }
        ans=max(ans,i-j+1);
      } 
      return ans;
    }
    
};