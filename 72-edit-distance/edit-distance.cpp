class Solution {
public:
    int minDistance(string &word1, string &word2) {
        int n=word2.length();
        int c=word1.length();
        int i,j,mini;
        int ar[n+1][c+1];
        for(i=0;i<=n;i++)
            ar[i][0]=i;
        for(j=0;j<=c;j++)
            ar[0][j]=j;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=c;j++)
            {
                if(word1[j-1]==word2[i-1])
                    ar[i][j]=ar[i-1][j-1];
                else
                    ar[i][j]=min(min(ar[i-1][j],ar[i-1][j-1]),ar[i][j-1])+1;
            }
        }
      
        return ar[n][c];
    }
};