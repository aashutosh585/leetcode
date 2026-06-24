class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        int n=nums.size();
        vector<vector<int>>arr;
        if(n==1) return nums;

        sort(nums.begin(), nums.end(), [](vector<int> &a, vector<int> &b){
            return a[0]<b[0];
        });

        int i=1;
        // fist el
        int x1=nums[0][0], x2=nums[0][1];
        while(i<n){
            // second el
            int y1=nums[i][0], y2= nums[i][1];

            if(x2>= y1 ){
                x2= max(x2, y2);
            }
            else{
                arr.push_back({x1,x2});
                x1=y1;
                x2=y2;
            }
            i++;
        }
        arr.push_back({x1,x2});
        return arr;
    }
};