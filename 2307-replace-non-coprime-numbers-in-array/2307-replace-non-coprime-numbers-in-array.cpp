class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int>ans;
        if(nums.size()==1) return nums;
        vector<int>st;

        int j=1;
        for(auto val:nums){
            int curr=val;
            while(!st.empty()){
                int x = gcd(st.back(),curr);
                if(x==1) break;

                curr = (st.back()/x)*curr;
                st.pop_back();
            }
            st.push_back(curr);

        }

       
       for(auto val:st) ans.push_back(val);

        return ans;

    }
};