class Solution {
public:
    map<pair<int,int>,bool>state;
    inline bool possible(int x, int y, int x1, int y1){
        return state[{x1,y1}]==false;
    }
    bool canMeasureWater(int &x, int &y, int &target) {
        state.clear();
        if(x>y)
            swap(x,y);  // make x jar as smaller
        pair<int,int>q={0,0};
        queue<pair<int,int>>ar;
        ar.push({q});
        while(!ar.empty()){
            q=ar.front();
            ar.pop();
            if(q.first+q.second==target)
                return true;
            state[{q.first,q.second}]=true;
            // Empty operation
            if(possible(x,y,0,0))   //empty both
                ar.push({0,0});
            if(possible(x,y,q.first,0)) //empty second
                ar.push({q.first,0});
            if(possible(x,y,0,q.second))   //empty first
                ar.push({0,q.second});

            // Fill operation
            if(possible(x,y,x,y))   //fill both
                ar.push({x,y});
            if(possible(x,y,x,q.second))    //fill first
                ar.push({x,q.second});
            if(possible(x,y,q.first,y))   //fill second
                ar.push({q.first,y});

            //transfer 2nd jar to 1st
            if(possible(x,y,min(x,q.first+q.second),max(0,q.second-(x-q.first)))) 
                ar.push({min(x,q.first+q.second),max(0,q.second-(x-q.first))}); 

            //transfer 1st to 2nd    
            if(possible(x,y,max(0,q.first-(y-q.second)),min(y,q.first+q.second)))
                ar.push({max(0,q.first-(y-q.second)),min(y,q.first+q.second)});
        }
        return false;
    }
};