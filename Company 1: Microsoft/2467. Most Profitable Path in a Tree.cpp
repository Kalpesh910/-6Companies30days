class Solution {
public:
    bool BOB(int bob, int steps, vector<int>& B, vector<int>& amount, vector<vector<int>>& adj, int prev){
        if(bob==0){  
            B[bob]=steps;
            return true;
        }
        else if(adj[bob].size()==1 && adj[bob][0] == prev)  return false;
        for(int i=0; i<adj[bob].size(); i++){
                if(adj[bob][i]!=prev){
                    bool temp = BOB(adj[bob][i], steps+1, B, amount, adj, bob);
                    if(temp){
                    B[bob]=steps;
                    return true;
                    }
                }
        }
        return false;
    }
    int Alice(int alice, int steps, vector<int>&B, vector<int>& amount, vector<vector<int>>& adj, int prev){
        int money;
        if(steps < B[alice] || B[alice]==0)
            money = amount[alice];
        else if(steps == B[alice])
            money = amount[alice]/2;
        else
            money = 0;
        if(adj[alice].size()==0)    return money;
        
        int temp=INT_MIN, flag=0;
        for(int i=0; i<adj[alice].size(); i++){
            if(adj[alice][i]!=prev){
                temp = max(temp, Alice(adj[alice][i], steps+1, B, amount, adj, alice));
                flag = 1;
            }
        }        
        if(flag==0) return money;
        return money+temp;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=edges.size();
        vector<vector<int>>adj(n+1);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>B(n+1);
        BOB(bob, 1, B, amount, adj, -1);
        int ans=Alice(0, 1, B, amount, adj, -1);
        return ans;
    }
};
