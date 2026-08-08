class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx==fx && sy==fy && t==1)
            return false;
        return t>=max(abs(fx-sx),abs(fy-sy));
    }
};