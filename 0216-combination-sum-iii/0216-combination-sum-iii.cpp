class Solution {
public:
    void solve(int idx,int k,int n,vector<int>&arr,vector<int>curr,vector<vector<int>>&ans,int sum){

       

        if(curr.size()==k ){
            if(sum == n ) ans.push_back(curr);
            return;
        }


        if(sum>n || curr.size() > k  || idx==arr.size()) return;

        for(int i=idx;i<arr.size();i++){
            curr.push_back(arr[i]);
            solve(i+1,k,n,arr,curr,ans,sum+arr[i]);
            curr.pop_back();
        }

        
    }
    vector<vector<int>> combinationSum3(int k, int n) {

        vector<int>arr= {1,2,3,4,5,6,7,8,9};
        vector<vector<int>>ans;
        vector<int>curr;

        solve(0,k,n,arr,curr,ans,0);
        return ans;
        
    }
};