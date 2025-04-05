class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans=1;
        int neg=0,zero=0;
        for(auto &val:nums){
            if(val==0){

            zero=1;
            break;
            }
            else if(val<0){
                neg++;
            }
        }

        if(zero==1) return 0;
        if(neg%2==0) return 1;

       

        return -1;
    }
};