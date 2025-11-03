class Solution {
public:
    int minCost(string col, vector<int>& needTime) {
        int ans=0,n=col.size(), sum=needTime[0], maxi=needTime[0];
        
        for(int i=1;i<n;i++){
            if(col[i-1]==col[i]){
                sum+=needTime[i];
                maxi=max(maxi,needTime[i]);
            }
            else{
                ans+=sum-maxi;
                sum=needTime[i],maxi=needTime[i];
            }
        }
        ans+=sum-maxi;
        return ans;

    }
};