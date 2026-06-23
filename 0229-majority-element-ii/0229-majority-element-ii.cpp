class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int can1=0, can2=0, n=nums.size();
        int cnt1=0, cnt2=0;

        for(int x:nums){
            if(can1==x) cnt1++;
            else if(can2==x) cnt2++;
            else if(cnt1==0){
                can1=x;
                cnt1=1;
            }
            else if(cnt2==0){
                can2=x;
                cnt2=1;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }

        cnt1=cnt2=0;
        for(int x:nums){
            if(x==can1) cnt1++;
            else if(x==can2) cnt2++;
        }

        vector<int>ans;

        if(cnt1> n/3) ans.push_back(can1);
        if(cnt2> n/3) ans.push_back(can2);

        return ans;
    }
};