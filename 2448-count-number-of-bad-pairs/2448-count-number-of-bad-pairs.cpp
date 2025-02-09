class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n=nums.size();
        long long ans=(n*(n-1))/2;
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            int x=i-nums[i];
            if(mpp.find(x)!=mpp.end()){
                ans-=mpp[x];
            }
        
                mpp[x]++;
    
        }
        return ans;
        
    }
};