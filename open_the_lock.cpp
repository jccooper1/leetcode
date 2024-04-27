class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<string>q;
        unordered_set<string>visited;
        unordered_set<string>deadset(deadends.begin(),deadends.end());
        if(deadset.find("0000") != deadset.end()) return -1;
        q.push("0000");
        visited.insert("0000");
        int ans=0;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                string curr=q.front();
                q.pop();
                if(curr==target) return ans;
                for(int j=0;j<4;j++){
                    string tmp1=curr;
                    string tmp2=curr;
                    tmp1[j] = (tmp1[j] == '9') ? '0' : tmp1[j] + 1;
                    tmp2[j] = (tmp2[j] == '0') ? '9' : tmp2[j] - 1;
                    if(visited.find(tmp1)==visited.end() and deadset.find(tmp1)==deadset.end()){
                        q.push(tmp1);
                        visited.insert(tmp1);
                    }
                    if(visited.find(tmp2)==visited.end() and deadset.find(tmp2)==deadset.end()){
                        q.push(tmp2);
                        visited.insert(tmp2);
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};