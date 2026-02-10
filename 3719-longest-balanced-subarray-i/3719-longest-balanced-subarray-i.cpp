class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans=0,n=nums.size();
        for(int i=0;i<n;i++){
            set<int>e,o;
            for(int j=i;j<n;j++){
                if(nums[j]%2==0) e.insert(nums[j]);
                else o.insert(nums[j]);

                if(e.size()==o.size()){
                    int x=e.size();
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};