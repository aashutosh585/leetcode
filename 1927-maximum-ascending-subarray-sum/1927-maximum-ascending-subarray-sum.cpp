class Solution {
public:
    int maxAscendingSum(vector<int>& arr) {
        int ans=arr[0],cnt=arr[0];

        for(int i=1;i<arr.size();i++){
            if(arr[i]>arr[i-1]){
                cnt+=arr[i];
            }
            else{
                cnt=arr[i];
            }
            ans=max(ans,cnt);

        }
        return ans;
    }
};