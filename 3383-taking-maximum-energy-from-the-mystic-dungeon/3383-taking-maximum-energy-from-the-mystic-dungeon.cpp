class Solution {
public:
    int maximumEnergy(vector<int>& en, int k) {
        unordered_map<int,int>mpp;
        int n=en.size();

        for(int i=0;i<n;i++){
            int val=mpp[i%k];

            val=max(val+en[i],en[i]);
            mpp[i%k]=val;
        }

        int ans=INT_MIN;
        for(auto it:mpp){
        ans=max(ans,it.second);
        cout<<it.second<<endl;
        }

        return ans;
    }
};