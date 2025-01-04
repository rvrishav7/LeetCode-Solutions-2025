#define ll long long int
#define N 10000001
typedef struct cell{
    ll x,y,d;
    cell(ll x, ll y, ll d){
        this->x =x;
        this->y =y;
        this->d=d;
    }
}cell;

class Solution {
public:
    int n,m,x,y,d;
    int xx[4]={0,0,1,-1};
    int yy[4]={1,-1,0,0};
    
    inline ll getDistance(int x1, int y1, int x2, int y2){
        return abs(x1-x2)+abs(y1-y2);
    }
    int maxDistance(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        
        long long int ans=-1,temp;
        vector<vector<bool>>visited(n,vector<bool>(m));
        vector<vector<long long int>>dis(n,vector<long long int>(m,N));
        queue<cell>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                    dis[i][j]=0;
                else{
                    cell temp(i,j,0);
                    dis[i][j]=N;
                    for(int p=0;p<4;p++){
                        x=temp.x+xx[p];
                        y=temp.y+yy[p];
                        if(x<0||y<0||x>=n||y>=m||grid[x][y]==0)
                            continue;
                        dis[i][j]=1;
                        temp.d=1;
                    }
                    if(temp.d==1)       //add water cells that are adjacent to land in the queue
                        q.push(temp);
                }
            }
        }
 
        while(!q.empty()){
            cell temp=q.front();
            q.pop();

            for(int i=0;i<4;i++){
                x=temp.x+xx[i];
                y=temp.y+yy[i];
                d=temp.d;
                if(x<0||y<0||x>=n||y>=m||grid[x][y])
                    continue;
                if(dis[x][y]>1+d){      //check if you are minimising the nearest distance for neighbouring water cell via front cell in queue
                    dis[x][y]=d+1;
                    cell temp(x,y,d+1);
                    q.push(temp);
                }
            }
        }
        //get maximum value among the min distances for each water cell
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                    continue;
                else
                    ans=max(dis[i][j],ans);  
            }
        }
        return (ans>=N)?-1:ans;
    }
};