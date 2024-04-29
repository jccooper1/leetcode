class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int cmp=nums[0];
        for(int i=1;i<nums.size();i++){
            cmp^=nums[i];
        }
        string tmp1=convert(cmp);
        string k_binary=convert(k);
        return find_diff(tmp1,k_binary);
    }
private:
    string convert(int n){
        string ans="";
        if(n==0) return "0";
        while(n>0){
            if(n%2) ans="1"+ans;
            else ans="0"+ans;
            n=n/2;
        }
        return ans;
    }
    int find_diff(string s1, string s2){
        int ans=0;
        int i=s1.length()-1;
        int j=s2.length()-1;
        while(i>=0 and j>=0){
            if(s1[i]!=s2[j]) ans++;
            i--;
            j--;
        }
        while(i>=0){
            if(s1[i]=='1') ans++;
            i--;
        }
        while(j>=0){
            if(s2[j]=='1') ans++;
            j--;
        }
        return ans;
    }
};