class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int curr_cap=capacity, steps=0;
        for(int i=0;i<plants.size();i++){
            if(curr_cap>=plants[i]){
                steps++;
                curr_cap-=plants[i];
            }
            else{
                steps+=(i);
                steps+=(i+1);
                curr_cap=capacity-plants[i];
            }
        }
        return steps;
    }
};