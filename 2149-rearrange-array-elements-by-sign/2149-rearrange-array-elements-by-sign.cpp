class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp(n);

        int i=0, j=1;
        for(auto &v:nums){
            if(v>=0){
                temp[i]=v;
                i+=2;
            }
            else{
                temp[j]=v;
                j+=2;
            }
        }

        return temp;
    }
};