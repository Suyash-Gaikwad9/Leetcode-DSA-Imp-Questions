class Solution {
public:

    bool check(vector<int>&stone1, vector<int>&stone2){
        if(stone1[0] == stone2[0] || stone1[1] == stone2[1]){
            return true;
        }
        return false;
    }

    void DFS(vector<int>&visited, vector<vector<int> > &Stones, int index){
        visited[index] = 1;

        for(int i = 0; i < Stones.size(); i++){
            if(!visited[i] && check(Stones[index], Stones[i])){
                DFS(visited, Stones, i);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int>visited(n, 0);
        int compo = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                compo++;
                DFS(visited, stones, i);
            }
        }
        return n - compo;
    }
};