class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>&can,int target,int idx,vector<int>arr){
        if(idx==can.size()){
            if(target==0){
                ans.push_back(arr);
            }
            return;
        }


        arr.push_back(can[idx]);
        if(target>=can[idx] )
        solve(ans,can,target-can[idx],idx+1,arr);
        arr.pop_back();

        int next = idx + 1;
        while (next < can.size() && can[next] == can[idx]) next++;

        solve(ans, can, target, next, arr);


    }
    vector<vector<int>> combinationSum2(vector<int>& can, int target) {
        sort(can.begin(),can.end());
        vector<vector<int>>ans;
        vector<int>arr;
        solve(ans,can,target,0,arr);
        return ans;
    }
};