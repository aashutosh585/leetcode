class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int tar) {
        int n=nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());

        if(n<4) return ans;

        for(int p=0;p<n-3;p++){
            if(p>0 && nums[p]==nums[p-1]) continue;

            for(int q=p+1;q<n-2;q++){
                if(q>p+1 && nums[q]==nums[q-1]) continue;

                int i=q+1;
                int j=n-1;

                while(i<j){
                    long long sum = 1LL * nums[p] + nums[q] + nums[i] + nums[j];

                    if(sum>tar) j--;
                    else if(sum<tar) i++;
                    else{
                        ans.push_back({nums[p], nums[q], nums[i], nums[j]});
                        i++;
                        j--;

                        while(i< j && nums[i]==nums[i-1]) i++;
                        while(i< j && nums[j]==nums[j+1]) j--;
                    }
                }
            }
        }
        return ans;
    }
};