class Solution {
public:
    int countSubstrings(string &s) {
        int ans=0,l,h,n=s.length();
        for(int i=0;i<n;i++){
            l=i;
            h=i+1;
            while(l>=0&&h<n&&s[l]==s[h]){
                l--;
                h++;
                ans++;
            }
        }
        for(int i=0;i<n;i++){   //odd length calculation with center as this ith element
            l=i;
            h=i;
            while(l>=0&&h<n&&s[l]==s[h]){
                ans++;
                l--;
                h++;
            }
        }
        return ans;
    }
};