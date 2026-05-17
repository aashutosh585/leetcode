class Solution {
public:
    
    bool dfs(vector<int> &arr, int i, vector<bool> &vis){
        if(i<0 || i>=arr.size() || vis[i]) return false;

        vis[i]=true;
        if(arr[i]==0) return true;

        return dfs(arr, arr[i]+i, vis) || dfs(arr, i-arr[i], vis);

    }

    bool canReach(vector<int>& arr, int s) {
        int n=arr.size();
        vector<bool>vis(n,false);
        return dfs(arr,s,vis);
    }
};