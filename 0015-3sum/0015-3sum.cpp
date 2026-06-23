class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();

        vector<vector<int>>ans;
        for(int p=0;p<n-2;p++){
            int k=-nums[p];
            if(p>0 && nums[p]==nums[p-1]) continue;

            int i=p+1, j=n-1;
            while(i<j){
                int sum=nums[i]+nums[j];

                if(sum>k) j--;
                else if(sum<k) i++;
                else{
                    ans.push_back({nums[p], nums[i], nums[j]});

                    i++;
                    j--;

                    while(i<j && nums[i]==nums[i-1]) i++;
                    while(i<j && nums[j]==nums[j+1]) j--;
                }
            }

        }
        return ans;
    }
};