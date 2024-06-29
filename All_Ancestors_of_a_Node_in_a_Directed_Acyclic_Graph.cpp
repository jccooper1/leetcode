class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            graph[edge[1]].push_back(edge[0]);
        }

        vector<vector<int>> ans(n);
        for (int i = 0; i < n; ++i) {
            vector<bool> visited(n, false);
            dfs(i, graph, ans[i], visited);
            sort(ans[i].begin(), ans[i].end());
        }
        return ans;
    }

private:
    void dfs(int node, vector<vector<int>>& graph, vector<int>& ancestors, vector<bool>& visited) {
        for (int ancestor : graph[node]) {
            if (!visited[ancestor]) {
                ancestors.push_back(ancestor);
                visited[ancestor] = true;
                dfs(ancestor, graph, ancestors, visited);
            }
        }
    }
};