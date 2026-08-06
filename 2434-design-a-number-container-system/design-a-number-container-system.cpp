class NumberContainers {
public:
    map<int,set<int>>mp;
    unordered_map<int,int>nums;
    NumberContainers() {
        mp.clear();
        nums.clear();
    }
    
    void change(int index, int number) {
        if(nums.find(index)!=nums.end()){
            int val=nums[index];
            mp[val].erase(index);
            if(mp[val].empty())
                mp.erase(val);
        }
        nums[index]=number;
        mp[number].insert(index);
    }
    
    int find(int number) {
        if(mp.find(number)==mp.end())
            return -1;
        return *mp[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */