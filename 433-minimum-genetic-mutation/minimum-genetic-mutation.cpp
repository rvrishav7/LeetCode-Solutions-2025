class Solution {
public:
    int calcDis(string x, string y){
        int count=0;
        for(int i=0;i<x.length();i++)
            count += (x[i] != y[i]);
        return count;
    }

    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> dict(bank.begin(), bank.end());
        if (!dict.count(end)) return -1; // end must be in bank

        queue<pair<string,int>> q;
        q.push({start,0});
        unordered_set<string> visited;
        visited.insert(start);

        while(!q.empty()){
            auto [s, steps] = q.front(); q.pop();

            if(s == end) return steps;

            for(auto &gene : dict){
                if(!visited.count(gene) && calcDis(s, gene) == 1){
                    visited.insert(gene);
                    q.push({gene, steps+1});
                }
            }
        }
        return -1;
    }
};
