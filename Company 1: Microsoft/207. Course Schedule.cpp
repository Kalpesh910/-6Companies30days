class Solution {
public:
    int dfs(int node, vector<vector<int>> &edge, vector<int> &vis, map<int, int>&mp){
        if(vis[node]==1)    return 1;
        if(edge[node].size()==0){
            vis[node]=1;
            return 1;
        }
        int t=1;
        mp[node]++;
        for(auto it: edge[node]){
            if(vis[it]!=1 && mp[it]!=0) return -1;
            else if(vis[it]!=1){
                int temp = dfs(it, edge, vis, mp);
                if(temp==-1)   return -1;
                vis[it]=1;
            }
        }
        mp[node]--;
        return 1;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>>edge(n);
        vector<int>vis(n, 0);
        for(auto it: prerequisites){
            edge[it[0]].push_back(it[1]);
        }
        map<int, int>mp;
        for(int i=0; i<edge.size(); i++){
            if(vis[i]==1)   continue;
            vis[i] = dfs(i, edge, vis, mp);
        }
        for(auto it: vis)   if(it!=1)  return false;
        return true;
    }
};
