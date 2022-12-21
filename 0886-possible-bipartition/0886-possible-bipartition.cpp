class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(n+1);
        vector<int>color(n+1, 0);
        vector<bool>visited(n+1, false);
        
        for(auto &dislike: dislikes){
            int u = dislike[0];
            int v = dislike[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        queue<int>q;
        for(int i = 1; i <= n; ++i){
            if(!visited[i]){
                color[i] = 1;
                q.push(i);
                while(!q.empty()){
                    int u = q.front();
                    q.pop();
                    if(visited[u]){
                        continue;
                    }
                    visited[u] = true;
                    for(auto v: adj[u]){
                        if(color[v] == color[u]){
                            return false;
                        }
                        if (color[v] == color[u]){
                            return false;
                        }
                        if (color[u] == 1){
                            color[v] = 2;
                        }
                        else{
                            color[v] = 1;
                        }
                        q.push(v);
                    }
                }
            }
        }
        return true;
    }
};