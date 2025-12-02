class Solution {
public:
    int mod=1e9+7;
    int countTrapezoids(vector<vector<int>>& arr) {
        int cnt=0;
        unordered_map<int,int>mpp;
        for(auto it:arr) mpp[it[1]]++;

        vector<int>a;
        long long sum=0;
        for(auto &it:mpp){
            int n=it.second;
            if(n>1){
               long long val=1LL *n * (n-1) /2;
               a.push_back(val%mod);
               sum+=val;
            }
        }
        int m=a.size();
        if(m<2) return 0;

        long long ans=0;
        for(int i=0;i<m-1;i++){
            sum-=a[i];
            ans= (ans+(sum*a[i])%mod) %mod;
        }
        // for(int i=0;i<m;i++){
        //     for(int j=i+1;j<m;j++){
        //         ans = (ans + (a[i] * a[j]) % mod) % mod;
        //     }
        // }
        
        return (int)ans;
    }
};