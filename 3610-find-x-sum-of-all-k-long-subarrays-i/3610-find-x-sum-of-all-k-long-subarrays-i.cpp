class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n=nums.size();
        vector<int>ans(n-k+1);
    
        for(int i=0;i<n-k+1;i++){

            unordered_map<int,int>mpp;
            for(int j=i;j<=i+k-1;j++) mpp[nums[j]]++;

            vector<pair<int,int>>v;
            for(auto it:mpp) v.push_back({it.first,it.second});

            sort(v.begin(),v.end(),[](auto &a,auto &b){
                if(a.second!=b.second) return a.second > b.second;;

                return b.first<a.first;
            });

            int cnt=0;
            for(int z=0;z<min(x,(int)v.size());z++) cnt += v[z].first * v[z].second;

            ans[i]=cnt;
        }
        return ans;
    }
};