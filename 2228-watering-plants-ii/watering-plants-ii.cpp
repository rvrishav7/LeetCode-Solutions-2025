class Solution {
public:
    int waterPlant(int plant, int &curr, int &cap){
        if(curr>=plant){
            curr-=plant;
            return 0;
        }
        curr=cap-plant;
        return 1;
    }
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int l=0,h=plants.size()-1,refills=0,currA=capacityA,currB=capacityB;
        while(l<=h){
            if(l==h){
                if(max(currA,currB)>=plants[l]){
                    //do nothing
                }
                else
                    refills++;
                break;
            }
            else{
                refills+=waterPlant(plants[l],currA,capacityA);
                refills+=waterPlant(plants[h],currB,capacityB);
                l++;
                h--;
            }
        }
        return refills;
    }
};
