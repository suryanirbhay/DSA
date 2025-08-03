class Solution {
  public:
    void check(vector<vector<int>>& adj,int node,int vis[],vector<int>& ls){
        vis[node]=1;
        
        ls.push_back(node);
        
        
        for(auto it: adj[node]){
            if(!vis[it]){
                check(adj,it,vis,ls);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int v=adj.size();
        int vis[v]={0};
        vector<int> ls;
        int start=0;
        check(adj,start,vis,ls);
        return ls;
    }
};