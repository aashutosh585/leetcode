class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int x=nums[n-1];
        int y=nums[n-2];
        int z=nums[n-3];

        if(x+y>z && y+z>x && x+z>y){
            return x+y+z;
        }
        x=y;
        y=z;

        for(int i=n-4;i>=0;i--){
            z=nums[i];
            if(x+y>z && y+z>x && x+z>y){
                return x+y+z;
            }
            x=y;
            y=z;

        }
        return 0;
    }
};