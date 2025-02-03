class Solution {
public:
    int longestMonotonicSubarray(vector<int>& arr) {
        int n=arr.size(),cnt=1,ans=1;
        for(int i=0;i<n-1;i++){
            if(arr[i]<arr[i+1]){
                cnt++;
            }
            else{
                cnt=1;
            }
            ans=max(ans,cnt);
        }
        cnt=1;
        for(int i=n-1;i>=1;i--){
            if(arr[i]<arr[i-1]){
                cnt++;
            }
            else{
                cnt=1;
            }
            ans=max(ans,cnt);
        }
        return ans;
        
    }
};