#include<vector>
using namespace std;
class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> tree(n);
        vector<int> count(n,0);
        vector<int> res(n,0);
        for(auto &edge:edges){
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        dfs(0,-1,count,res,tree);
        dfs2(0,-1,count,res,tree,n);
        return res;

    }
    private:
    void dfs(int node,int parent,vector<int>&count,vector<int>&res,vector<vector<int>>&tree){
        for(auto &child:tree[node]){
            if(child==parent) continue;
            dfs(child,node,count,res,tree);
            count[node]+=count[child];
            res[node]+=res[child]+count[child];
        }
        count[node]++;
    }
    void dfs2(int node,int parent,vector<int>&count,vector<int>&res,vector<vector<int>>&tree,int n){
        for(auto &child:tree[node]){
            if(child==parent) continue;
            res[child]=res[node]-count[child]+n-count[child];
            dfs2(child,node,count,res,tree,n);
        }
    }
};