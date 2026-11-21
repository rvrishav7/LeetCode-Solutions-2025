class MagicDictionary {
public:
    set<string>s;
    MagicDictionary() {
       s.clear(); 
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto &x: dictionary)
            s.insert(x);
    }
    
    bool search(string searchWord) {
        for(auto &x: s){
            int diff=0;
            if(x.length() == searchWord.length()){
                for(int i=0;i<x.length();i++)
                    if(x[i]!=searchWord[i])
                        diff++;
            }

            if(diff==1)
                return true;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */