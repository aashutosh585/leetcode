class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int ans=0,maxi=arr[0],n=arr.size();
        for(int i=1;i<n;i++){
            ans=max(ans,arr[i]-maxi);
            maxi=min(maxi,arr[i]);
        }
        return ans;
    }
};