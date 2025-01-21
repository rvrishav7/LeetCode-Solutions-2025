#define MOD 1000000007
class Solution {
public:
    string decimalToBinary(int n)
    {
        string s = bitset<64> (n).to_string();
        const auto loc1 = s.find('1');
        
        if(loc1 != string::npos)
            return s.substr(loc1);
        
        return "0";
    }
    int concatenatedBinary(int n) {
        long long int ans=0;
        for(int i=1;i<=n;i++){
            string t=decimalToBinary(i);
            for(auto &x:t){
                ans=(ans*2)%MOD;
                ans=((ans%MOD)+((x-'0')))%MOD;
            }
        }
        return ans;
    }
};