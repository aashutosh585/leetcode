class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>&cand,int target,int idx,vector<int>arr){
        if(idx==cand.size()) {
            if(target==0){
                ans.push_back(arr);
            }
            return;
        }

        solve(ans,cand,target,idx+1,arr);
        int x=cand[idx];
        while(x<=target){
            arr.push_back(cand[idx]);
            solve(ans,cand,target-x,idx+1,arr);
            x+=cand[idx];
            
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        vector<vector<int>>ans;
        vector<int>arr;
        solve(ans,cand,target,0,arr);
        return ans;
    }
};