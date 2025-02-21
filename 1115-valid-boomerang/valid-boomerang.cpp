class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b){
        if(a[0]==b[0])
            return a[1]<a[1];
        return a[0]<b[0];
    }
    bool inline equal(vector<int>&a,vector<int>&b)
    {
        return a[0]==b[0]&&a[1]==b[1];
    }
    bool isBoomerang(vector<vector<int>>& points) {
        if((points[0][1]==points[1][1])&&(points[1][1]==points[2][1]))
            return false;
        if((points[0][0]==points[1][0])&&(points[1][0]==points[2][0]))
            return false;
        if(equal(points[0],points[1])||equal(points[1],points[2])||equal(points[0],points[2]))
            return false;
    
        sort(points.begin(),points.end(),cmp);
       return ((double)(points[1][1]-points[0][1])/(double)(points[1][0]-points[0][0]))
       !=  ((double)(points[2][1]-points[1][1])/(double)(points[2][0]-points[1][0]));
     
    }
};