
class Solution {
public:
    int judge(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || !grid[i][j]) return 0;
        else return 1;
    }
    int ct(vector<vector<int>>& grid, int i, int j){
       return judge(grid, i-1, j) + judge(grid, i+1, j) + judge(grid, i, j+1) + judge(grid, i, j-1);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]){
                    ans += 4 - ct(grid, i, j);
                }
            }
        }
        return ans;
    }
};