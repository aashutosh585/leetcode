class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();

        for(int k=0;k<n;k++){
            int val=-1;
            bool f=true;
            for(int i=0;i<n;i++){
                int j= (i+k)%n;
                if(val<=nums[j]) val= nums[j];
                else{
                    f=false;
                    break;
                }
            }
            if(f) return true;
        }

        return false;
        
    }
};