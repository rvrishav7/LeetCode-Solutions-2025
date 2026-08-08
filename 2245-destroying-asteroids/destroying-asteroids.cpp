class Solution {
public:
    bool asteroidsDestroyed(long  mass, vector<int>& asteroids) {
       sort(asteroids.begin(),asteroids.end()); 
       for(auto &x: asteroids){
            if(mass<x)
                return false;
            mass+=x;
       }
       return true;
    }
};