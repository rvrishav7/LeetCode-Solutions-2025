#define ll long long int
#define MOD 1000000007
class Solution {
    map<char,vector<char>>graph;
    
    void inline init() {
        graph['a']={'e'};
        graph['e']={'a','i'};
        graph['i']={'a','e','o','u'};
        graph['o']={'i','u'};
        graph['u']={'a'};
    }
public:
    int countVowelPermutation(int &n) {
        ll ans=0;
        map<char,ll>count;
        init();
       count['a']=count['e']=count['i']=count['o']=count['u']=1;  //n=1;
        
        for(ll i=2;i<=n;i++){
            map<char,ll>temp;
            ll cnt=0;
            for(auto &x: graph){
                cnt=count[x.first];
                for(auto &c: x.second)
                    temp[c]=(temp[c]+cnt)%MOD;
            }
            count=temp;
        }
        for(auto &x: count){
            ans=(ans+x.second)%MOD;
        }
        return ans;
    }
};