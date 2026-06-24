class Solution {
public:
    int merge(int l, int mid, int h, vector<int>&nums){

        int cnt = 0;
        int j = mid + 1;

        for(int i = l; i <= mid; i++) {
            while (j <= h && nums[i] > 2LL * nums[j]) j++;
            cnt += (j - (mid + 1));
        }

        vector<int>temp;
        int i=l;
        j=mid+1;

        while(i<=mid && j<=h){
            if(nums[i]>nums[j]) temp.push_back(nums[j++]);
            else temp.push_back(nums[i++]); 
        }

        while(i<=mid) temp.push_back(nums[i++]);
        while(j<=h) temp.push_back(nums[j++]);

        for(int k=l;k<=h;k++) nums[k]= temp[k-l];

        return cnt;
    }

    int solve(int i, int j, vector<int> &nums){
        if(i>=j) return 0;

        int mid=(i+j)/2;

        int l= solve(i, mid, nums);
        int r= solve(mid+1, j, nums);
        int c = merge(i, mid, j, nums);

        return l+r+c;
    }
    int reversePairs(vector<int>& nums) {
        return solve(0, nums.size()-1, nums);
    }
};