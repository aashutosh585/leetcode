class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans=0,cnt=0,sum=0;
        int i=0,j=0,n=nums.size();
        while(i<n){
            sum+=nums[i];
            while(sum*(i+1-j)>=k && i>=j){
                sum-=nums[j];
                j++;
            }
            cnt+=i-j+1;
            i++;
        }
        return cnt;
    }
};