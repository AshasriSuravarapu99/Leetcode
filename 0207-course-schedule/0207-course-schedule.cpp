class Solution {
public:
    bool dfs(int i,  vector<vector<int>> &adjList, vector<int> &vis, vector<int> &pathVis){
        vis[i] = 1;
        pathVis[i] = 1;

        for(auto it : adjList[i]){
            if(!vis[it]){
                if(dfs(it,adjList,vis,pathVis) == true){
                    return true;
                }
            }
            else if(pathVis[it]){
                return true;
            }
        }

        pathVis[i] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        for(int i = 0; i < prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adjList[v].push_back(u);
        }
        vector<int>vis(numCourses,0);
        vector<int>pathVis(numCourses,0);
        for(int i = 0; i < numCourses; i++){
            if(!vis[i]){
                if(dfs(i,adjList,vis,pathVis) == true){
                    return false;
                }
            }
        }
        return true;
    }
};